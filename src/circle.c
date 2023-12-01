/**
 * @file circle.c
 * @ref BTS1230
 * @copyright Bern University of Applied Sciences, 2021. All rights reserved.
 *
 * @author Pascal Mainini <pascal.mainini@bfh.ch>
 * @date 20.09.2021
 *
 * @brief Implementation of the functions declared in circle.h.
 */
#include "circle.h"

double area(double radius) { return PI * radius * radius; }

double circumference(double radius) { return 2 * radius * PI; }
