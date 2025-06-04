import fetch from 'node-fetch';
import * as dotenv from 'dotenv';

dotenv.config();

async function main() {
    const args = process.argv.slice(2);
    if (args.length === 0) {
        console.log("Please provide a prompt as a command line argument.");
        process.exit(1);
    }

    const prompt = args.join(" ");
    const apiKey = process.env.TOGETHER_API_KEY;

    if (!apiKey) {
        console.error("API key not found in .env file.");
        process.exit(1);
    }

    const requestBody = {
        model: "nvidia/Llama-3.1-Nemotron-70B-Instruct-HF",
        messages: [
            {
                role: "user",
                content: prompt
            }
        ]
    };

    try {
        const response = await fetch("https://api.together.xyz/v1/chat/completions", {
            method: "POST",
            headers: {
                "Authorization": `Bearer ${apiKey}`,
                "Content-Type": "application/json"
            },
            body: JSON.stringify(requestBody)
        });

        if (!response.ok) {
            console.error(`Request failed with status: ${response.status}`);
            const errorText = await response.text();
            console.error(errorText);
            process.exit(1);
        }

        const data = await response.json();
        const content = data.choices[0].message.content;
        console.log(content);
    } catch (error) {
        console.error("Error during request:", error);
        process.exit(1);
    }
}

main();
