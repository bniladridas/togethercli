#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cJSON.h"

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if(ptr == NULL) {
        // out of memory
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

char* read_api_key(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open %s\n", filename);
        return NULL;
    }
    char line[512];
    char* api_key = NULL;
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "TOGETHER_API_KEY=", 17) == 0) {
            size_t len = strlen(line);
            if (line[len-1] == '\n') line[len-1] = '\0';
            api_key = strdup(line + 17);
            break;
        }
    }
    fclose(file);
    return api_key;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s \"Your prompt here\"\n", argv[0]);
        return 1;
    }

    char* api_key = read_api_key(".env");
    if (!api_key) {
        fprintf(stderr, "API key not found in .env file\n");
        return 1;
    }

    const char* prompt = argv[1];

    CURL *curl;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *headers = NULL;
        char auth_header[512];
        snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", api_key);
        headers = curl_slist_append(headers, auth_header);
        headers = curl_slist_append(headers, "Content-Type: application/json");

        const char* url = "https://api.together.xyz/v1/chat/completions";

        // Create JSON body
        cJSON *root = cJSON_CreateObject();
        cJSON_AddStringToObject(root, "model", "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF");

        cJSON *messages = cJSON_CreateArray();
        cJSON *message_obj = cJSON_CreateObject();
        cJSON_AddStringToObject(message_obj, "role", "user");
        cJSON_AddStringToObject(message_obj, "content", prompt);
        cJSON_AddItemToArray(messages, message_obj);
        cJSON_AddItemToObject(root, "messages", messages);

        char *post_data = cJSON_PrintUnformatted(root);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Parse JSON response
            cJSON *json = cJSON_Parse(chunk.memory);
            if (!json) {
                fprintf(stderr, "Error parsing JSON response\n");
            } else {
                cJSON *choices = cJSON_GetObjectItem(json, "choices");
                if (choices && cJSON_IsArray(choices)) {
                    cJSON *first_choice = cJSON_GetArrayItem(choices, 0);
                    if (first_choice) {
                        cJSON *message = cJSON_GetObjectItem(first_choice, "message");
                        if (message) {
                            cJSON *content = cJSON_GetObjectItem(message, "content");
                            if (content && cJSON_IsString(content)) {
                                printf("%s\n", content->valuestring);
                            } else {
                                fprintf(stderr, "Content field missing or not a string\n");
                            }
                        } else {
                            fprintf(stderr, "Message field missing\n");
                        }
                    } else {
                        fprintf(stderr, "No choices found\n");
                    }
                } else {
                    fprintf(stderr, "Choices field missing or not an array\n");
                }
                cJSON_Delete(json);
            }
        }

        free(post_data);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize curl\n");
    }

    free(chunk.memory);
    free(api_key);
    curl_global_cleanup();

    return 0;
}
