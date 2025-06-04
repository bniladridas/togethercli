#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <curl/curl.h>
#include "json.hpp"

// For convenience
using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string read_api_key(const std::string& env_path) {
    std::ifstream env_file(env_path);
    if (!env_file.is_open()) {
        throw std::runtime_error("Failed to open .env file");
    }
    std::string line;
    while (std::getline(env_file, line)) {
        if (line.find("TOGETHER_API_KEY=") == 0) {
            return line.substr(std::string("TOGETHER_API_KEY=").length());
        }
    }
    throw std::runtime_error("API key not found in .env file");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " \"Your prompt here\"" << std::endl;
        return 1;
    }

    std::string prompt = argv[1];
    std::string api_key;
    try {
        api_key = read_api_key(".env");
    } catch (const std::exception& e) {
        std::cerr << "Error reading API key: " << e.what() << std::endl;
        return 1;
    }

    json body = {
        {"model", "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF"},
        {"messages", {{{"role", "user"}, {"content", prompt}}}}
    };

    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + api_key).c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, "https://api.together.xyz/v1/chat/completions");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        std::string body_str = body.dump();
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body_str.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            try {
                auto json_response = json::parse(readBuffer);
                std::cout << json_response["choices"][0]["message"]["content"] << std::endl;
            } catch (const std::exception& e) {
                std::cerr << "Failed to parse JSON response: " << e.what() << std::endl;
                std::cerr << "Response was: " << readBuffer << std::endl;
            }
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Failed to initialize curl" << std::endl;
    }

    curl_global_cleanup();
    return 0;
}
