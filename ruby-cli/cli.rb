require 'net/http'
require 'json'
require 'dotenv/load'

def main
  prompt = ARGV.join(' ')
  if prompt.empty?
    puts "Please provide a prompt as a command line argument."
    exit 1
  end

  api_key = ENV['TOGETHER_API_KEY']
  if api_key.nil? || api_key.empty?
    puts "API key not found in .env file."
    exit 1
  end

  uri = URI('https://api.together.xyz/v1/chat/completions')
  request_body = {
    model: "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF",
    messages: [
      {
        role: "user",
        content: prompt
      }
    ]
  }

  http = Net::HTTP.new(uri.host, uri.port)
  http.use_ssl = true
  request = Net::HTTP::Post.new(uri.path, {
    'Content-Type' => 'application/json',
    'Authorization' => "Bearer #{api_key}"
  })
  request.body = request_body.to_json

  response = http.request(request)

  if response.code.to_i != 200
    puts "Request failed with status: #{response.code}"
    puts response.body
    exit 1
  end

  data = JSON.parse(response.body)
  content = data['choices'][0]['message']['content']
  puts content
end

main if __FILE__ == $0
