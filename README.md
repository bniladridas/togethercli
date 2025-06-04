# Together API CLI Tools

Effortlessly interact with the Together API using the `nvidia/Llama-3.1-Nemotron-70B-Instruct-HF` model. This repository offers sleek, powerful CLI tools crafted in multiple languages.

## Languages

- **Rust**: Fast, reliable prompt-to-response interaction.
- **R**: Seamless API integration for data-driven workflows.
- **Scala**: Elegant, scalable command-line prompting.
- **Fortran**: Robust API calls via curl system integration.

## Setup

1. Create a `.env` file in the root or language-specific folder:
   ```env
   TOGETHER_API_KEY=your_api_key_here
   ```
2. Replace `your_api_key_here` with your Together API key.

## Usage

Each CLI takes a prompt as a command-line argument and delivers the API’s response with precision.

- **Rust**
  ```sh
  cd rust-cli
  cargo run -- "Your prompt here"
  ```
- **R**
  ```sh
  Rscript r-cli/cli.R "Your prompt here"
  ```
- **Scala**
  ```sh
  cd scala-cli
  sbt run "Your prompt here"
  ```
- **Fortran**
  ```sh
  gfortran fortran-cli/main.f90 -o fortran-cli/together_cli
  ./fortran-cli/together_cli "Your prompt here"
  ```

## Notes

- Ensure your `.env` file contains a valid API key.
- Fortran uses `curl` for HTTP requests.
- Special characters in prompts are escaped for reliable JSON payloads.

## License

Provided as-is, without warranty.
