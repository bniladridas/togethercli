#!/usr/bin/env Rscript

library(httr)
library(jsonlite)
library(dotenv)

# Load environment variables from .env file
load_dot_env(file = "../.env")

api_key <- Sys.getenv("TOGETHER_API_KEY")

if (api_key == "") {
  stop("API key not found in environment variables.")
}

args <- commandArgs(trailingOnly = TRUE)

if (length(args) == 0) {
  stop("Please provide a prompt as a command line argument.")
}

prompt <- args[1]

url <- "https://api.together.xyz/v1/chat/completions"

body <- list(
  model = "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF",
  messages = list(
    list(
      role = "user",
      content = prompt
    )
  )
)

response <- POST(
  url,
  add_headers(
    Authorization = paste("Bearer", api_key),
    "Content-Type" = "application/json"
  ),
  body = toJSON(body, auto_unbox = TRUE)
)

if (status_code(response) != 200) {
  stop(paste("API request failed with status", status_code(response)))
}

cat("Response headers:\n")
print(headers(response))

content <- content(response, as = "text", encoding = "UTF-8")
cat("Raw JSON response:\n", content, "\n")  # Debug print
cat("Is valid JSON? ", jsonlite::validate(content), "\n")

json_content <- fromJSON(content, simplifyVector = FALSE)

cat(json_content$choices[[1]]$message$content, "\n")
