# SPDX-FileCopyrightText: 2025 University of Manchester
#
# SPDX-License-Identifier: apache-2.0

# Makefile to build the Monte Carlo Pi estimation program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = monte_carlo_pi

# Source files
SRCS = monte_carlo_pi.cpp

# Default target
all: $(TARGET)

# Build the target executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean up build files
clean:
	rm -f $(TARGET)
