using System;
using System.Net.Http;
using System.Net.Http.Headers;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using DotNetEnv;

class Program
{
    static async Task Main(string[] args)
    {
        Env.Load();

        string apiKey = Environment.GetEnvironmentVariable("TOGETHER_API_KEY");
        if (string.IsNullOrEmpty(apiKey))
        {
            Console.WriteLine("API key not found in environment variables.");
            return;
        }

        if (args.Length < 1)
        {
            Console.WriteLine("Usage: dotnet run -- \"Your prompt here\"");
            return;
        }

        string prompt = args[0];

        var client = new HttpClient();
        client.DefaultRequestHeaders.Authorization = new AuthenticationHeaderValue("Bearer", apiKey);
        client.DefaultRequestHeaders.Accept.Add(new MediaTypeWithQualityHeaderValue("application/json"));

        var requestBody = new
        {
            model = "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF",
            messages = new[]
            {
                new { role = "user", content = prompt }
            }
        };

        string json = JsonSerializer.Serialize(requestBody);
        var content = new StringContent(json, Encoding.UTF8, "application/json");

        try
        {
            HttpResponseMessage response = await client.PostAsync("https://api.together.xyz/v1/chat/completions", content);
            response.EnsureSuccessStatusCode();

            string responseBody = await response.Content.ReadAsStringAsync();
            using JsonDocument doc = JsonDocument.Parse(responseBody);
            var root = doc.RootElement;

            var messageContent = root.GetProperty("choices")[0].GetProperty("message").GetProperty("content").GetString();
            Console.WriteLine(messageContent);
        }
        catch (HttpRequestException e)
        {
            Console.WriteLine($"Request error: {e.Message}");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Unexpected error: {e.Message}");
        }
    }
}
