/**
 * @file user.c
 * @ref BTS1230
 * @copyright Bern University of Applied Sciences, 2023. All rights reserved.
 *
 * @author Paul Holderbaum <paul.holderbaumondoua@students.bfh.ch>
 * @date 01.12.2023
 *
 * @brief RSA User module.
 *
 * This is the module that contains user defined helper functions.
 */


#include <stdio.h>
#include <string.h>
#include <stddef.h>

/**
 * @brief Calculates Modular Exponentiation.
 *
 * This function calculates the modular Exponentiation m^e (mod n)
 * The code is inspired from chatgpt
 *
 * @param The base, the exponent, the modulo
 * @return the modular exponentiation 
 * −1 if the message is invalid or an error has occurred.
 */
long modular_exponentiation(long base, long exp, long mod){
	long result = 1;
	base = base % mod;
	
	while(exp >0){
		if((exp % 2) == 1)
			result = (result * base) % mod;
		exp = exp  >> 1;
		base = (base * base) % mod;
	}

	return result;
	
}


/**
 * @brief Computes GCD with Extended Euclidiean Algorithm
 *
 * Computes the Extended Euclidean Algorithm.  The original source code is from
 * geekforgeeks <https://www.geeksforgeeks.org/c-program-for-basic-and-extended-euclidean-algorithms-2/>
 *
 * @param phi, public exponent,
 * @return The GCD.
 */

long gcdExtended(long phi, long e, long* x, long* y)
{
    // Base Case
    if (phi == 0) {
        *x = 0;
        *y = 1;
        return e;
    }

    long  x1, y1; // To store results of recursive call
    long gcd = gcdExtended(e % phi, phi, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (e / phi) * x1;
    *y = x1;

    return gcd;
}


