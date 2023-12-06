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
	int number;
	printf("Enter a number to check if it's prime: ");
	if( scanf("%d", &number) == 1 && number > 0 ){
		if(is_prime(number) == 1)
			printf("%d is prime\n", number);
		else if(is_prime(number)==-1){
			printf("%d is invalid\n", number);
		}
		else
			printf("%d is not prime\n", number);
	}
	else{
		// if there is an error clear the input buffer
		int c;
		while((c = getchar()) != '\n' && c!=EOF);
		printf("\nInvalid!\n");
	}
}
