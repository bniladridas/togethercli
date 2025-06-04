#!/bin/bash

# Load API key from .env file
if [ -f .env ]; then
  export $(grep -v '^#' .env | xargs)
fi

if [ -z "$TOGETHER_API_KEY" ]; then
  echo "API key not found in .env file."
  exit 1
fi

if [ $# -eq 0 ]; then
  echo "Please provide a prompt as a command line argument."
  exit 1
fi

PROMPT="$*"

response=$(curl -s -X POST "https://api.together.xyz/v1/chat/completions" \
  -H "Authorization: Bearer $TOGETHER_API_KEY" \
  -H "Content-Type: application/json" \
  -d '{
    "model": "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF",
    "messages": [
      {
        "role": "user",
        "content": "'"$PROMPT"'"
      }
    ]
  }')

echo "$response" | jq -r '.choices[0].message.content'
