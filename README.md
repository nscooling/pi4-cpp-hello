# pi4-cpp-hello

Minimal C++23 project for a Raspberry Pi 4, used to verify a native GCC + CMake + Ninja toolchain and remote development from VS Code (Remote-SSH, clangd, gdb).

## Requirements

- Raspberry Pi 4 (or any aarch64 Linux) running Raspberry Pi OS Trixie / Debian 13
- GCC 14+ (for `<print>` / `std::println`)

```
sudo apt install -y build-essential cmake ninja-build gdb clangd
```

## Build and run

```
cmake -S . -B build -G Ninja
cmake --build build
./build/hello
```

Expected output:

```
x = 1
x = 2
x = 3
x = 4
```

`CMAKE_EXPORT_COMPILE_COMMANDS` is on, so `build/compile_commands.json` is generated for clangd.

## VS Code (Remote-SSH)

Recommended extensions on the remote: clangd, CMake Tools, C/C++ (debugging only, with its IntelliSense disabled).

After the first configure of a fresh clone, run **clangd: Restart language server** so clangd picks up `compile_commands.json`.

Suggested remote settings for a 4 GB Pi:

```
"cmake.generator": "Ninja",
"cmake.parallelJobs": 3,
"clangd.arguments": ["-j=2", "--background-index", "--header-insertion=never"],
"C_Cpp.intelliSenseEngine": "disabled"
```
