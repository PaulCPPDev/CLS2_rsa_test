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
#include "../include/user.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define MSG_SIZE 100


int main(void) {
	/*char message[MSG_SIZE];
	long cryp[MSG_SIZE];
	long e, n;
	size_t elements = MSG_SIZE;

	printf("Enter the public exponent e: ");
	scanf("%ld", &e);
	printf("\nEnter the modulus n: ");
	scanf("%ld", &n);
	printf("\nEnter a message to be encrypted:\n");
	int msg_size = scanf("%s", message);
	if(scanf("%[^\n]", message)<=msg_size){
		printf("\n%s", message);
	}
	
	int was_encrypted = encrypt(e, n, message, cryp, msg_size);

	if(!was_encrypted){
		printf("\nError\n");
	}
	else{
		printf("\nThe encrypted message is: \n");
		for(int i=0 ; i< msg_size; i++){
			printf("%ld",cryp[i]);
		}
		printf("\n");
	}*/

	// Modular exponentiation function
	long base, exp, mod;
	printf("\nEnter the base m: ");
        scanf("%ld", &base);
	printf("\nEnter the exponent e: ");
        scanf("%ld", &exp);
	printf("\nEnter the modulus n: ");
        scanf("%ld", &mod);
	long modexp = modular_exponentiation(base, exp, mod);
	printf("\nThe modular exponentiation is = %ld\n", modexp);



}
