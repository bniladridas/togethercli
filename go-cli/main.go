package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"strings"

	"github.com/joho/godotenv"
)

type Message struct {
	Role    string `json:"role"`
	Content string `json:"content"`
}

type RequestBody struct {
	Model    string    `json:"model"`
	Messages []Message `json:"messages"`
}

type Choice struct {
	Message Message `json:"message"`
}

type ResponseBody struct {
	Choices []Choice `json:"choices"`
}

func main() {
	err := godotenv.Load()
	if err != nil {
		fmt.Println("Error loading .env file")
		os.Exit(1)
	}

	apiKey := os.Getenv("TOGETHER_API_KEY")
	if apiKey == "" {
		fmt.Println("TOGETHER_API_KEY not set in .env file")
		os.Exit(1)
	}

	if len(os.Args) < 2 {
		fmt.Println("Please provide a prompt as a command line argument")
		os.Exit(1)
	}

	prompt := strings.Join(os.Args[1:], " ")

	requestBody := RequestBody{
		Model: "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF",
		Messages: []Message{
			{
				Role:    "user",
				Content: prompt,
			},
		},
	}

	jsonData, err := json.Marshal(requestBody)
	if err != nil {
		fmt.Println("Error marshalling request body:", err)
		os.Exit(1)
	}

	req, err := http.NewRequest("POST", "https://api.together.xyz/v1/chat/completions", bytes.NewBuffer(jsonData))
	if err != nil {
		fmt.Println("Error creating request:", err)
		os.Exit(1)
	}

	req.Header.Set("Authorization", "Bearer "+apiKey)
	req.Header.Set("Content-Type", "application/json")

	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		fmt.Println("Error sending request:", err)
		os.Exit(1)
	}
	defer resp.Body.Close()

	if resp.StatusCode != http.StatusOK {
		bodyBytes, _ := ioutil.ReadAll(resp.Body)
		fmt.Printf("Request failed with status %d: %s\n", resp.StatusCode, string(bodyBytes))
		os.Exit(1)
	}

	bodyBytes, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		fmt.Println("Error reading response body:", err)
		os.Exit(1)
	}

	var responseBody ResponseBody
	err = json.Unmarshal(bodyBytes, &responseBody)
	if err != nil {
		fmt.Println("Error unmarshalling response body:", err)
		os.Exit(1)
	}

	if len(responseBody.Choices) > 0 {
		fmt.Println(responseBody.Choices[0].Message.Content)
	} else {
		fmt.Println("No choices found in response")
	}
}
