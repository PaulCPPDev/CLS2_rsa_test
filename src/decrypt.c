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
        printf("decrypt()\n");
}


