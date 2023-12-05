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
 * This is the module that contains user defined helper functions, it contains the
 * functions string_to_integer()
 */


#include <stdio.h>
#include <string.h>
#include <stddef.h>


/**
 * @brief Converts a string into a long integer.
 *
 * This function converts the message into a long integer (m) in the range, 1 < m < n-1
 *
 *
 * The code is inspired from chatgpt
 *
 * @param The message to convert, the modulus n
 * @return the converted integer m, 
 * −1 if the message is invalid or an error has occurred.
 */
long string_to_long(const char* message, long n){
	if( (message == NULL) || (n < 0))
		return -1;
	else{
		long result = 0;

		// Iterate through each character in the string
		for(size_t i = 0; i < strlen(message); i++ ) {
			// Update the result by shifting and adding the ASCII value
			result = (result << 8) | message[i];
		}

		// Make sure the result is within the range [o, n -1 ]
		result = result % n;
	
		return result;
	}
}


/**
 * @brief Converts a string into a long integer.
 *
 * This function converts the message into a long integer (m) in the range, 1 < m < n-1
 *
 *
 * The code is inspired from chatgpt
 *
 * @param The message to convert, the modulus n
 * @return the converted integer m, 
 * −1 if the message is invalid or an error has occurred.
 */
void long_to_string( long number, char * str){
	int i = 0;
	while (number > 0 ){
		str[i++] = number % 256; // Take the lowe 8 bits as an ascii
		number = number >> 8;
	}
	str[i] = '\0'; // Null-terminate the string
}




/**
 * @brief Calculates Modular Exponentiation.
 *
 * This function calculates the modular Exponentiation m^e (mod n)
 * The code is inspired from chatgpt
 * This function works
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


