# Use Arduino CLI image as base
FROM ubuntu:22.04

# Install system dependencies
RUN apt-get update && apt-get install -y \
    curl \
    git \
    python3 \
    python3-pip \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Install Arduino CLI
RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
RUN mv bin/arduino-cli /usr/local/bin/

# Configure Arduino CLI
RUN arduino-cli config init
RUN arduino-cli core update-index
RUN arduino-cli core install arduino:avr

# Install common Arduino libraries
RUN arduino-cli lib install "Servo"
RUN arduino-cli lib install "LiquidCrystal"
RUN arduino-cli lib install "WiFi"

# Set working directory
WORKDIR /workspace

# Welcome message
RUN echo 'echo "Arduino development environment ready!"' >> /etc/bash.bashrc
RUN echo 'echo "Use arduino-cli commands to compile and upload sketches"' >> /etc/bash.bashrc
RUN echo 'echo "Example: arduino-cli compile --fqbn arduino:avr:uno sketch.ino"' >> /etc/bash.bashrc