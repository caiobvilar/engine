FROM ubuntu:24.04

# Avoid prompts from apt
ENV DEBIAN_FRONTEND=noninteractive

# Install essential build tools and development dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc-14 \
    g++-14 \
    cmake \
    ninja-build \
    git \
    wget \
    pkg-config \
    # Build dependencies for SDL3
    libx11-dev \
    libxext-dev \
    libxrandr-dev \
    libxcursor-dev \
    libxinerama-dev \
    libxi-dev \
    libxss-dev \
    libxxf86vm-dev \
    libxfixes-dev \
    libxrender-dev \
    libxtst-dev \
    libwayland-dev \
    libxkbcommon-dev \
    libegl1-mesa-dev \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libvulkan-dev \
    libpulse-dev \
    libasound2-dev \
    libdbus-1-dev \
    libudev-dev \
    libibus-1.0-dev \
    libdrm-dev \
    libgbm-dev \
    libfmt-dev \
    libpipewire-0.3-dev \
    libdecor-0-dev \
    libsamplerate0-dev \
    # Debugging and profiling tools
    gdb \
    gdbserver \
    valgrind \
    strace \
    ltrace \
    # Performance profiling
    linux-tools-generic \
    perf-tools-unstable \
    # Memory debugging
    electric-fence \
    # Code formatting
    clang-format \
    # Additional useful tools
    vim \
    nano \
    && rm -rf /var/lib/apt/lists/*

# Set GCC 14 as default (latest major version!)
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-14 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-14 100 \
    && update-alternatives --install /usr/bin/cc cc /usr/bin/gcc 100 \
    && update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++ 100

# Build and install SDL3 (latest from main branch)
# Disable advanced features to avoid complex dependency issues
RUN cd /tmp && \
    git clone --depth 1 https://github.com/libsdl-org/SDL.git && \
    cd SDL && \
    mkdir build && cd build && \
    cmake .. -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/usr/local \
        -DSDL_TEST=OFF \
        -DSDL_SHARED=ON \
        -DSDL_STATIC=ON && \
    ninja && \
    ninja install && \
    ldconfig && \
    cd /tmp && rm -rf SDL

# Build and install spdlog (latest from master)
RUN cd /tmp && \
    git clone --depth 1 https://github.com/gabime/spdlog.git && \
    cd spdlog && \
    mkdir build && cd build && \
    cmake .. -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/usr/local && \
    ninja && \
    ninja install && \
    cd /tmp && rm -rf spdlog

# Download and install GLM (header-only, latest from master)
RUN cd /tmp && \
    git clone --depth 1 https://github.com/g-truc/glm.git && \
    cd glm && \
    mkdir build && cd build && \
    cmake .. -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/usr/local && \
    ninja install && \
    cd /tmp && rm -rf glm

# Download and install nlohmann_json (header-only, latest from master)
RUN cd /tmp && \
    git clone --depth 1 https://github.com/nlohmann/json.git && \
    cd json && \
    mkdir build && cd build && \
    cmake .. -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/usr/local \
        -DJSON_BuildTests=OFF && \
    ninja install && \
    cd /tmp && rm -rf json

# Download and install EnTT (header-only library, latest from master)
# Manual installation since EnTT doesn't use standard CMake install
RUN cd /tmp && \
    git clone --depth 1 https://github.com/skypjack/entt.git && \
    cd entt && \
    mkdir -p /usr/local/include && \
    cp -r src/entt /usr/local/include/ && \
    mkdir -p /usr/local/lib/cmake/EnTT && \
    echo '# EnTT CMake configuration file' > /usr/local/lib/cmake/EnTT/EnTTConfig.cmake && \
    echo 'include(CMakeFindDependencyMacro)' >> /usr/local/lib/cmake/EnTT/EnTTConfig.cmake && \
    echo 'if(NOT TARGET EnTT::EnTT)' >> /usr/local/lib/cmake/EnTT/EnTTConfig.cmake && \
    echo '    add_library(EnTT::EnTT INTERFACE IMPORTED)' >> /usr/local/lib/cmake/EnTT/EnTTConfig.cmake && \
    echo '    set_target_properties(EnTT::EnTT PROPERTIES' >> /usr/local/lib/cmake/EnTT/EnTTConfig.cmake && \
    echo '        INTERFACE_INCLUDE_DIRECTORIES "/usr/local/include"' >> /usr/local/lib/cmake/EnTT/EnTTConfig.cmake && \
    echo '    )' >> /usr/local/lib/cmake/EnTT/EnTTConfig.cmake && \
    echo 'endif()' >> /usr/local/lib/cmake/EnTT/EnTTConfig.cmake && \
    cd /tmp && rm -rf entt

# Download and install ImGui (latest from master with SDL3 support)
RUN cd /tmp && \
    git clone --depth 1 https://github.com/ocornut/imgui.git && \
    mkdir -p /usr/local/include/imgui && \
    cd imgui && \
    cp *.h *.cpp /usr/local/include/imgui/ && \
    cp backends/imgui_impl_sdl3.h backends/imgui_impl_sdl3.cpp /usr/local/include/imgui/ && \
    cp backends/imgui_impl_sdlrenderer3.h backends/imgui_impl_sdlrenderer3.cpp /usr/local/include/imgui/ && \
    cp backends/imgui_impl_opengl3.h backends/imgui_impl_opengl3.cpp /usr/local/include/imgui/ && \
    cd /tmp && rm -rf imgui

# Set working directory
WORKDIR /workspace

# Verify installations
RUN gcc --version && g++ --version && cmake --version

# Default command
CMD ["/bin/bash"]
