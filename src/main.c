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
#include <stdio.h>
#include <stddef.h>

int main(void) {
	int n = 0;
	long arr2[10];
	printf("Enter the number of longs: ");
	scanf("%d", &n);
	long arr[n];
	printf("\nEnter %d longs\n",n);
	for(int i = 0; i<n; i++){
		printf("arr[%d] = ",i);
		scanf("%ld", &arr[i]);
		printf("\n");
	}

	printf("\n");
	display_cryp(arr, n);
	printf("\n");

	/*is_prime(1);
	encrypt(1,1,"a", "aa",1);
	decrypt(1,1,"a","aa",1);*/
}
