#!/bin/bash

set -e  # stop on error

BUILD_DIR="build"
BUILD_TYPE="Debug"

echo "=== Building PersonalEngine ($BUILD_TYPE) ==="

# Create build dir if missing
mkdir -p $BUILD_DIR

# Run CMake configuration step
cmake -S . -B $BUILD_DIR -DCMAKE_BUILD_TYPE=$BUILD_TYPE

# Build
cmake --build $BUILD_DIR --config $BUILD_TYPE

# Run the engine if the binary exists
ENGINE_BINARY="$BUILD_DIR/Debug/PersonalEngine.exe"


if [ -f "$ENGINE_BINARY" ]; then
    echo "=== Running PersonalEngine ==="
    "$ENGINE_BINARY"
else
    echo "Error: Engine binary not found!"
    exit 1
fi
