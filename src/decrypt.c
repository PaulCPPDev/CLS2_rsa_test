/**
 * @file decrypt.c
 * @ref BTS1230
 * @copyright Bern University of Applied Sciences, 2023. All rights reserved.
 *
 * @author Paul Holderbaum <paul.holderbaumondoua@students.bfh.ch>
 * @date 01.12.2023
 *
 * @brief RSA Decryption module.
 *
 * This is the module that decrypts messages. It contains the
 * function encrypt()
 */

#include "../include/user.h"
#include <stdio.h>
#include <stddef.h>






/**
 * @brief Decrypts the encrypted message
 * 
 * This function decrypts the whole string cryp of length elements and stores the result, 
 * which must be '\0'-terminated, in msg.
 *
 * @param  
 * @return The number of characters that have been decrypted plus 1 for the terminating '\0',
 * or −1 in case of an error.
 */
int decrypt(long d, long n, long cryp[], char msg[], size_t elements){
        if(cryp == NULL || msg == NULL || elements == 0)
		return -1;
	
	size_t msg_length = 0;
	for(size_t i= 0; i<elements ; i++){
		if(cryp[i] == '\0')
			break;
		long decrypted_value = modular_exponentiation(cryp[i], d, n);

		// Check if the decrypted value is valic ASCII code
		if (decrypted_value >= 0 && decrypted_value <= 127){
			printf("%ld", decrypted_value);
			msg[i] = (char) decrypted_value;
			msg_length++;
		}
		else{
			msg[i] = '?';
			msg_length++;
		}
	}
	
	// Null-terminate the decrypted string
	msg[msg_length] = '\0';
		
	return msg_length + 1; // Return the number of characters decrypted plus 1 for '\0'
}


