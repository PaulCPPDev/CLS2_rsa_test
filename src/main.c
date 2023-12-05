/**
 * @file main.c
 * @ref BTS1230
 * @copyright Bern University of Applied Sciences, 2023. All rights reserved.
 *
 * @author Paul Gregor Holderbaum Ondoua <paul.holderbaumondoua@students.bfh.ch>
 * @date 01.12.2023
 *
 * @brief  (main module).
 *
 * This is the main module of the modular programming example. It contains the
 * main()-function.
 */

#include "../include/io.h" 
#include "../include/keygen.h"
#include "../include/encrypt.h"
#include "../include/decrypt.h"
#include <stdio.h>
#include <stddef.h>

int main(void) {
	long phi=0;
	long exponent,e;
	printf("Enter PHI(n) = (p-1)(q-1): ");
	scanf("%ld",&phi);
	printf("Enter a public exponent e: ");
	scanf("%ld", &e);
	
	exponent = private_exponent(e,phi);
	if(exponent >= 0)
		printf("\ne = %ld\n", exponent);
	if(exponent <= -1)
		printf("\nError\n");


}
