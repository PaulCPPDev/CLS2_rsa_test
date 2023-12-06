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
	char message[MSG_SIZE];
	long cryp[MSG_SIZE];
	long e, n, p, q, phi_;
	size_t elements = MSG_SIZE;

	// ask for p & q
	printf("Enter p: ");
	scanf("%ld", &p);
	printf("\nEnter q: ");
	scanf("%ld", &q);
	
	// Calculate n
	n = modulus(p,q);
	printf("\nn = %ld", n);

	// Calculate phi
	phi_ = phi(p,q);
	printf("\nphi(n) = %ld\n", phi_);

	// Generate public exponent
	e = public_exponent(phi_);
	printf("The public exponent e = %ld\n",e);
	
	//printf("\nEnter the modulus n: ");
	//scanf("%ld", &n);
	
	// Generate the private exponent
	long private_key = private_exponent(e,phi_);
	printf("\nThis is you private key, make sure to hide it well\n%ld", private_key);


	// Enter message to be encrypted
	printf("\nEnter a message to be encrypted:\n");
	
	int msg_size = 0;
	
	scanf(" ");
	if(scanf("%[^\n]", message) >= 1)
		msg_size = strlen(message);
		
	printf("\nmsg_size = %d  message =%s\n",msg_size, message);
	
	int was_encrypted = encrypt(e, n, message, cryp, msg_size);

	if(!was_encrypted){
		printf("\nError\n");
	}
	else{
		printf("\nThe encrypted message is: \n");
		int num_written= display_cryp(cryp, msg_size);
		printf("\nNumber of characters written = %d", num_written);

		printf("\nUsing the old method the message is: \n");
		for(int i=0 ; i< msg_size; i++){
			printf("%ld",cryp[i]);
		}
		printf("\n");
	}
	

	// Decryption
	char decrypted_message[100];
	long d = 1;
	printf("Enter the decryption key d: ");
	scanf("%ld", &d);
	int num_char = decrypt(d, n, cryp, decrypted_message, msg_size);
	
	printf("\nNumber of elements decrypted =  %d\n", num_char);

	if(num_char <= 0)
		printf("\nError decrypting the message\n");	
	if(decrypted_message == NULL)
		printf("\nDecrypted message is Null\n");
	else
		printf("\nDecrypted message is not null\n");

	printf("%s\n",decrypted_message);

	
	printf("\n");


}
