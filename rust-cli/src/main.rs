use dotenv::dotenv;
use std::env;
use reqwest::Client;
use serde::{Deserialize, Serialize};
use std::error::Error;

#[derive(Serialize)]
struct Message {
    role: String,
    content: String,
}

#[derive(Serialize)]
struct ChatCompletionRequest {
    model: String,
    messages: Vec<Message>,
}

#[derive(Deserialize)]
struct ChatCompletionResponse {
    choices: Vec<Choice>,
}

#[derive(Deserialize)]
struct Choice {
    message: MessageContent,
}

#[derive(Deserialize)]
struct MessageContent {
    content: String,
}

#[tokio::main]
async fn main() -> Result<(), Box<dyn Error>> {
    dotenv().ok();

    let api_key = env::var("TOGETHER_API_KEY")?;
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        eprintln!("Usage: {} <prompt>", args[0]);
        std::process::exit(1);
    }

    let prompt = &args[1];

    let client = Client::new();

    let request_body = ChatCompletionRequest {
        model: "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF".to_string(),
        messages: vec![Message {
            role: "user".to_string(),
            content: prompt.to_string(),
        }],
    };

    let res = client
        .post("https://api.together.xyz/v1/chat/completions")
        .bearer_auth(api_key)
        .json(&request_body)
        .send()
        .await?;

    if !res.status().is_success() {
        eprintln!("Request failed with status: {}", res.status());
        std::process::exit(1);
    }

    let response_body: ChatCompletionResponse = res.json().await?;

    if let Some(choice) = response_body.choices.first() {
        println!("{}", choice.message.content);
    } else {
        eprintln!("No response choices found");
    }

    Ok(())
}
