// SPDX-FileCopyrightText: 2025 University of Manchester
//
// SPDX-License-Identifier: apache-2.0

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  const int num_samples = 1000000; // Number of random samples
  int inside_circle = 0;

  // Seed the random number generator
  std::srand(std::time(0));

  for (int i = 0; i < num_samples; ++i) {
    // Generate random point (x, y) in the range [-1, 1]
    double x = (std::rand() / (double)RAND_MAX) * 2.0 - 1.0;
    double y = (std::rand() / (double)RAND_MAX) * 2.0 - 1.0;

    // Check if the point is inside the unit circle
    if (x * x + y * y <= 1.0) {
      ++inside_circle;
    }
  }

  // Calculate the estimated value of π
  double pi_estimate = 4.0 * inside_circle / num_samples;

  std::cout << "Estimated value of π: " << pi_estimate << std::endl;

  return 0;
}
