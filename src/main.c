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
	


	long elements,n,d;

	printf("\nEnter a number: ");
	scanf("%ld", &elements);
	
	long cryp[elements];
	char msg[elements*2];
	
       printf("\nEnter the encrypted message: ");	
	
	int num_values = read_cryp(cryp, elements);
	
	if (num_values>=0) {
		printf("\nEncrypted message stored in cryp: ");
		for(int i=0; i < num_values ; i++){
			printf("%ld ", cryp[i]);
		}
		printf("\n");
	}

	
	printf("\nEnter the modulo\n");
	scanf("%ld", &n);

	printf("\nEnter your private key\n");
	scanf("%ld", &d);


	// decrypt the  message
	long values_decrypted = decrypt(d, n, cryp, msg, elements);

	printf("\nnumber of values decrypted = %ld", values_decrypted);
	printf("\ndecrypted message is \n%s\n", msg);



}
