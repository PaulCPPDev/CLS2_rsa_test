/**
 * @file encrypt.c
 * @ref BTS1230
 * @copyright Bern University of Applied Sciences, 2023. All rights reserved.
 *
 * @author Paul Holderbaum <paul.holderbaumondoua@students.bfh.ch>
 * @date 01.12.2023
 *
 * @brief RSA Encryption module.
 *
 * This is the module that encrypts messages. It contains the
 * function encrypt()
 */

#include "../include/user.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>






/**
 * @brief Encrypts the message
 *
 * This function encrypts the whole string msg of length elements and stores the result, 
 * which must be '\0'-terminated, in cryp.
 *
 * @param The public key exponent e, The message to be encrypted, The cypher, and the size of elements
 * @return The number of characters that have been encrypted plus 1 for the terminating '\0', 
 * or −1 in case of an error. 
 */



int encrypt(long e, long n, char msg[], long cryp[], size_t elements) {
	if (msg == NULL || cryp == NULL || elements == 0) {
		return -1; // Invalid input
	}

	// loop through the message to check if the message is null terminated
	size_t is_null_terminated = 0;
	for (size_t i = 0; i<= elements; i++){
		if (msg[i] == '\0'){
			is_null_terminated++;
			break;
		}
	}

	// check if the message is null terminated
	if(!is_null_terminated)
		return -1;


	// convert the message into numbers
	size_t count = 0;	
	for (count  = 0; count < elements; count++) {
		cryp[count] = modular_exponentiation((long)(msg[count]), e, n);
    	}

    cryp[elements] = '\0'; // Null-terminate the encrypted string

    return count + 1; // Return the number of characters encrypted plus 1 for '\0'
}

/*
int encrypt(long e, long n, char msg[], long cryp[], size_t elements){
        if( (msg == NULL) || (cryp == NULL) || (e<0) || (n<0) )
		return -1;
	else{

		// loop through the message to check if the message is null terminated
		size_t is_null_terminated = 0;
		for (size_t i = 0; i<= elements; i++){
			if (msg[i] == '\0'){
				is_null_terminated++;
				break;
			}
		}

		// check if the message is null terminated
		if(!is_null_terminated)
			return -1;
		else{
			// convert the message to an integer in the range [0, n-1] using ASCII
			long m = string_to_long(msg,n);

			// convert the integer message into cypher text ( encrypted text)
			// using modular exponentiation
			long cypher_number =  modular_exponentiation(m, e, n);

			

			
			// convert the cypher number back into text 
			char cypher_message[elements];
		       	long_to_string(cypher_number,cypher_message);
			

			// check the size of the cryp destination
			size_t size =(size_t)(sizeof(cryp)/sizeof(cryp[0]));

			if(size < elements)
				return -1;
			else{
				int count = 0;
				for (size_t i = 0; i < elements; i++){
					cryp[i] = cypher_message[i];
					count++;
				} 
				return count;

			}


		}
	
	}
}*/

