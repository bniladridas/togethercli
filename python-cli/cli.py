import os
import sys
import requests
from dotenv import load_dotenv

def main():
    load_dotenv()
    api_key = os.getenv("TOGETHER_API_KEY")
    if not api_key:
        print("API key not found in environment variables.")
        sys.exit(1)

    if len(sys.argv) < 2:
        print("Usage: python cli.py \"Your prompt here\"")
        sys.exit(1)

    prompt = sys.argv[1]

    url = "https://api.together.xyz/v1/chat/completions"
    headers = {
        "Authorization": f"Bearer {api_key}",
        "Content-Type": "application/json"
    }
    json_data = {
        "model": "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF",
        "messages": [
            {
                "role": "user",
                "content": prompt
            }
        ]
    }

    response = requests.post(url, headers=headers, json=json_data)
    if response.status_code != 200:
        print(f"API request failed with status {response.status_code}")
        sys.exit(1)

    data = response.json()
    try:
        print(data["choices"][0]["message"]["content"])
    except (KeyError, IndexError):
        print("Unexpected response format.")
        sys.exit(1)

if __name__ == "__main__":
    main()
