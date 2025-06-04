import io.github.cdimascio.dotenv.Dotenv;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import org.json.JSONArray;
import org.json.JSONObject;

public class Main {
    public static void main(String[] args) throws Exception {
        if (args.length == 0) {
            System.out.println("Please provide a prompt as a command line argument.");
            System.exit(1);
        }

        String prompt = String.join(" ", args);

        Dotenv dotenv = Dotenv.load();
        String apiKey = dotenv.get("TOGETHER_API_KEY");
        if (apiKey == null || apiKey.isEmpty()) {
            System.err.println("API key not found in .env file.");
            System.exit(1);
        }

        HttpClient client = HttpClient.newHttpClient();

        JSONObject message = new JSONObject();
        message.put("role", "user");
        message.put("content", prompt);

        JSONArray messages = new JSONArray();
        messages.put(message);

        JSONObject requestBody = new JSONObject();
        requestBody.put("model", "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF");
        requestBody.put("messages", messages);

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create("https://api.together.xyz/v1/chat/completions"))
                .header("Authorization", "Bearer " + apiKey)
                .header("Content-Type", "application/json")
                .POST(HttpRequest.BodyPublishers.ofString(requestBody.toString()))
                .build();

        HttpResponse<String> response = client.send(request, HttpResponse.BodyHandlers.ofString());

        if (response.statusCode() == 200) {
            JSONObject jsonResponse = new JSONObject(response.body());
            String content = jsonResponse.getJSONArray("choices")
                    .getJSONObject(0)
                    .getJSONObject("message")
                    .getString("content");
            System.out.println(content);
        } else {
            System.err.println("Request failed with status code: " + response.statusCode());
            System.err.println("Response body: " + response.body());
        }
    }
}
