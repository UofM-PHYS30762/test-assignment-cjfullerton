// SPDX-FileCopyrightText: 2025 University of Manchester
//
// SPDX-License-Identifier: apache-2.0

#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  // Seed the random number generator
  std::srand(std::time(0));

  // Generate a random number between 0 and 100
  int target = std::rand() % 101;
  int guess;
  int attempts = 5;

  std::cout << "I have generated a random number between 0 and 100. You have 5 "
               "guesses to find it.\n";

  for (int i = 0; i < attempts; ++i) {
    std::cout << "Guess #" << (i + 1) << ": ";
    std::cin >> guess;

    if (guess == target) {
      std::cout << "Congratulations! You guessed the correct number.\n";
      return 0;
    } else if (guess < target) {
      std::cout << "Your guess is too low.\n";
    } else {
      std::cout << "Your guess is too high.\n";
    }
  }

  std::cout << "Sorry, you've used all your guesses. The correct number was "
            << target << ".\n";

  return 0;
}
