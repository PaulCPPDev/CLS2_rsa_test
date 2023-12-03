/**
 * @file io.c
 * @ref BTS1230
 * @copyright Bern University of Applied Sciences, 2023. All rights reserved.
 *
 * @author Paul Holderbaum <paul.holderbaumondoua@students.bfh.ch>
 * @date 01.12.2023
 *
 * @brief Input and Output of the API.
 *
 * This is the I/O module of the API. It contains the
 * functions read_number(), display_cryp(), display_cryp(), display_msg()
 */


#include <stdio.h>
#include <stddef.h>



/**
 * This function asks the user to enter a positive number. If the user enters an invalid 
 * value, the function asks again. After 3 tries, it terminates and returns −1
 *
 * @return A positive int value, or −1 in case of error.
 */
int read_number(){
	double number = -1;
	int count = 0;

	while(number < 0 && count < 3){
		printf("Enter a positive number: ");
		int numberRead = scanf("%lf", &number);
		if(numberRead == 1){
			printf("\n");
			count++;	
		}
		else{
			count++;
			while(numberRead != 1 && count < 3) {
		
				// read the input until there is a new line without storing the value
				scanf("%*[^\n]");
				printf("\nEnter a positive number: ");
				numberRead = scanf("%lf", &number);

				printf(" \n");
				count++;
			}
		}
	}
	
	if(number > 0){
		return (int)number;
	}
	else{
		return -1;
	}

}






/**
 * @brief Writes all elements of the encrypted message
 *
 * This function writes all elements of the encrypted message cryp with length elements
 * as numerical values to stdout. The values have to be separated by spaces. Example: “1 42 23 0”.
 *
 * @param array of type long, number of elements in the array
 * @return The number of values written or −1 in case of an error.
 */
int display_cryp(long cryp[], size_t elements){
	// check that the array is not empty
	if((cryp != NULL) && (elements > 0) ){
		int i;
		for(i=0; i< elements; i++){
			printf("%ld ", cryp[i]);
		}
		printf("\n");
		return i;
	}
	else {
		return -1;
	}
}





/**
 * @brief Reads and stores encrypted messages
 *
 * This function reads in an encrypted message from stdin and stores it in cryp. The
 * message consists of numerical values separated by spaces, the last value has to be
 * the value 0 (example: “1 42 23 0”). No more than elements values, including the 
 * final value 0, must be read, the message may however also be shorter! It is an error,
 * if the message to be read is longer than the size of cryp, which is given by elements.
 *
 * @param array of type long, number of elements in the array
 * @return The number of values read, or −1 in case of an error.
 */
int read_cryp(long cryp[], size_t elements){
	printf("read_cryp\n");
}




/**
 * @brief Displays the message
 *
 * Writes the decrypted message msg of length elements as plain text to stdout.
 *
 * @param message, size of the message
 * @return The number of characters written, or −1 in case of an error.
 */
int display_msg(char msg[], size_t elements){
	printf("display_msg\n");
}

