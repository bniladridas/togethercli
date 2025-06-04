# C CLI for Together API

## Prerequisites

- Install libcurl development libraries.
- The cJSON library source is included in the `cjson` directory.

## Build Instructions

```bash
gcc -o c-cli/c-cli c-cli/main.c c-cli/cjson/cJSON.c -I c-cli/cjson -lcurl
```

## Usage

```bash
./c-cli/c-cli "Your prompt here"
```

The program reads the API key from the `.env` file located in the current directory.

## Notes

- Ensure the `.env` file contains the line:

```
TOGETHER_API_KEY=your_api_key_here
