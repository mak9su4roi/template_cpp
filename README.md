# Lab work <mark>ZERO</mark>: <mark>Option Parser</mark>
Author: <mark>[Maksym Bilyk](https://github.com/mak9su4roi)</mark><br>
Variant: <mark>The One And Only</mark>
## Prerequisites
- `cmake` >= `3.21`
- `c++17` compatible compiler
- preferrably `POSIX` OS

### Compilation
-   ```bash
    git clone git@github.com:mak9su4roi/template_cpp.git
    ```
-   ```bash
    cd template_cpp
    ```
-   ```bash
    git submodule init && git submodule update
    ```
-   ```bash
    tools/vcpkg/bootstrap-vcpkg.sh
    ```
    <mark> OR <mark>
    ```bash
    tools\vcpkg\bootstrap-vcpkg.bat
    ```
-   ```bash
    cmake --preset base
    ```
-   ```bash
    cmake --build --preset base
    ```

### Usage

-   ```bash
    build/bin/option-parser -A
    ```