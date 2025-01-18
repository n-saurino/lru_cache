# Use an Ubuntu base image
FROM ubuntu:20.04

# Set the working directory
WORKDIR /workspace

# Install required dependencies
RUN apt-get update && apt-get install -y \
    software-properties-common \
    gcc-11 \                     # Install GCC 11 for C++20 support
    g++-11 \                     # Install G++ 11
    cmake \                      # Install CMake for build configuration
    ninja-build \                # Install Ninja build system
    make \                       # Make utility
    git \                        # Git for version control
    vim \                        # Optional: Text editor
    gdb \                        # Optional: Debugger \
    && apt-get clean && rm -rf /var/lib/apt/lists/*

# Set GCC 11 as the default compiler
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 100

# Set environment variables
ENV LANG=C.UTF-8 \
    LC_ALL=C.UTF-8 \
    DEBIAN_FRONTEND=noninteractive

# Default command to keep the container running
CMD ["/bin/bash"]
