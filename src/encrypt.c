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


#include <stdio.h>
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
int encrypt(long e, long n, char msg[], long cryp[], size_t elements){
        printf("encrypt()\n");
}

