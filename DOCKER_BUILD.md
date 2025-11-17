# Docker Build Environment

This Docker setup provides a clean GCC 14 build environment with all dependencies pre-installed, using the latest versions from GitHub.

## Prerequisites

- Docker installed and running
- Docker Compose installed

## Quick Start

### 1. Build the Docker image

```bash
docker-compose build
```

### 2. Start the container

```bash
docker-compose up -d
```

### 3. Enter the container

```bash
docker-compose exec engine-dev bash
```

### 4. Build your project inside the container

**Using CMake Presets (Recommended):**

```bash

# Debug build (with sanitizers and full debugging symbols)
cmake --preset debug
cmake --build --preset debug

# Release build (optimized with LTO)
cmake --preset release
cmake --build --preset release

# Release with debug info (for profiling)
cmake --preset relwithdebinfo
cmake --build --preset relwithdebinfo
```

**Manual configuration:**

```bash
# Create build directory
mkdir -p build/Debug
cd build/Debug

# Configure CMake
cmake ../.. -DCMAKE_BUILD_TYPE=Debug

# Build
cmake --build . -j$(nproc)
```

## Usage Commands

### Start container

```bash
docker-compose up -d
```

### Stop container

```bash
docker-compose down
```

### Execute commands in running container

```bash
docker-compose exec engine-dev <command>
```

### View container logs

```bash
docker-compose logs -f engine-dev
```

### Rebuild image (if Dockerfile changes)

```bash
docker-compose build --no-cache
```

### Clean up everything (including build cache)

```bash
docker-compose down -v
```

## Alternative: One-off commands

You can also build directly without entering the container:

```bash
# Build project in one command
docker-compose run --rm engine-dev bash -c "cmake --preset release && cmake --build --preset release"
```

## Notes

- The container uses Ubuntu 24.04 LTS with **GCC 14.2.0** (latest major version!)
- All project files are mounted at `/workspace` in the container (with SELinux compatibility for Fedora)
- Changes made in the container to project files are reflected on your host system

## Installed Dependencies (All Latest from Source!)

✅ **SDL3 3.3.3** (bleeding edge from main branch)
✅ **spdlog 1.16.0** (latest from master)
✅ **GLM** (latest from master)
✅ **nlohmann_json 3.12.0** (latest from master)
✅ **EnTT** (latest from master)
✅ **ImGui** (latest from master, including SDL3 backends)

## Debugging Tools

✅ **GDB 15.0** - GNU Debugger with all features
✅ **Valgrind 3.22.0** - Memory debugging and profiling
✅ **strace** - System call tracer
✅ **ltrace** - Library call tracer
✅ **perf** - Performance profiling tools

## CMake Presets

Three build configurations are pre-configured:

- **debug** - Full debugging symbols, Address Sanitizer (ASAN), Undefined Behavior Sanitizer (UBSAN), no optimization
- **release** - Maximum optimization (-O3), native CPU architecture tuning, Link-Time Optimization (LTO)
- **relwithdebinfo** - Optimized build with debug symbols for profiling with Valgrind/perf
