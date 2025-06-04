# C++ CLI for Together API

## Prerequisites

- Install libcurl development libraries.
- Download and include [nlohmann/json.hpp](https://github.com/nlohmann/json/releases/latest) in the project directory or install via package manager.

## Build Instructions

```bash
g++ -std=c++17 -o cxx-cli main.cpp -lcurl
```

Make sure `json.hpp` is in the include path or in the same directory as `main.cpp`.

## Usage

```bash
./cxx-cli "Your prompt here"
```

The program reads the API key from the `.env` file located one directory above (`../.env`).

## Notes

- Ensure the `.env` file contains the line:

```
TOGETHER_API_KEY=your_api_key_here
