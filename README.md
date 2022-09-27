# Jolly

Joseph's Open Source C++ Library

This library contains various useful, general purpose functions and macros.

## Table of Contents

- [Build](#build)
- [Install](#install)
- [Features](#features)

## Build

To build with CMake:

``` bash
cmake --preset=gcc-release-ninja \
cd build/gcc-release-ninja \
ninja
```

To build with Meson:

``` bash
meson build/meson/release --buildtype release \
cd build/meson/release \
meson compile
```

## Install

To install with CMake:

``` bash
sudo ninja install
```

To install with Meson:

``` bash
meson install
```

## Features

Trim functions to remove whitespace in strings:

``` cpp
std::string s1 = " left";
std::string s2 = "right ";
std::string s3 = " both ";

ltrim(s1) // "left"
rtrim(s2) // "right"
trim(s3) // "both"
```

Prompt input analogous to Python's `input()`:

``` cpp
std::string result = prompt("Enter any integer: ");
```

Switch & case statements with strings:

``` cpp
// Enables hash constexpr function
USE_JOLLY_HASH_FUNCTION
const char* key = "value";
unsigned int val = 0;
switch(hash(key) {
  case hash("value"): val = 1;
}
std::cout << val << std::endl; // 1

```

Macros for using `spdlog` in a linked, shared library and binary target.

``` cpp
#include <spdlog/logger.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/stdout_sinks.h>

// Your logger name and custom format if any
static const std::string logger_name = "jolly";
static const std::string logger_format = "[%Y-%m-%d %H.%M.%S.%e] [%^%l%$] [%s:%#] %v"; /* [2022-08-20 23:16:43.347] [debug] [app.cpp:3] Message! */

// Share one logger across the binary & library targets
USE_JOLLY_SPDLOG_SETUP_LOGGER_FUNCTION
USE_JOLLY_SPDLOG_SETUP_LOGGING_FUNCTION

// Enables dynamic toggling of spdlog logging statements at runtime, and initializes the logger
USE_JOLLY_SPDLOG_INIT_SPDLOG_DYNAMIC_LOGGING_FUNCTION

int main(int argc, char** argv) {
    init_spdlog_dynamic_logging(1);

    SPDLOG_DEBUG("Hello, World!");
}

```

## Contribute

Contributions are welcome. Feel free to open an issue for a feature or bug request.
