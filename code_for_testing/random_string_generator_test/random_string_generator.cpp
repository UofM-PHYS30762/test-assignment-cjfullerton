// SPDX-FileCopyrightText: 2025 University of Manchester
//
// SPDX-License-Identifier: apache-2.0

#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  const int length = 50; // Length of the random string
  std::string random_string;
  random_string.reserve(length);

  // Seed the random number generator
  std::srand(std::time(0));

  for (int i = 0; i < length; ++i) {
    // Generate a random letter (either uppercase or lowercase)
    char random_letter = 'A' + std::rand() % 26;
    if (std::rand() % 2) {
      random_letter = std::tolower(random_letter);
    }
    random_string += random_letter;
  }

  // Print the random string
  std::cout << "Random string: " << random_string << std::endl;

  return 0;
}
