/**
 * @file main.c
 * @ref BTS1230
 * @copyright Bern University of Applied Sciences, 2021. All rights reserved.
 *
 * @author Pascal Mainini <pascal.mainini@bfh.ch>
 * @date 20.09.2021
 *
 * @brief Demonstrate modular C programs (main module).
 *
 * This is the main module of the modular programming example. It contains the
 * main()-function.
 */
#include "circle.h" // note " " instead of < >!
#include <stdio.h>

int main(void) {
  double radius = 42.23;
  printf("The circumference of a circle with radius %.2f is %.2f.\n", radius,
         circumference(radius));
  printf("The area of a circle with radius %.2f is %.2f.\n", radius,
         area(radius));
}
