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
#include <stdlib.h>


/**
 * This function asks the user to enter a positive number. If the user enters an invalid 
 * value, the function asks again. After 3 tries, it terminates and returns −1
 *
 * @return A positive int value, or −1 in case of error.
 */
int read_number(){
	int number;
	int trial = 0;

	while (trial < 3){
		printf("\nEnter a positive number: ");
		
		// check if the input is valid
		if(scanf("%d", &number)== 1 && number > 0){
			return number;
		}
		// Invalid input
		else{
			// Clear the Input buffer to avoid infinite loops when the input is invalid
			int c;
			while((c = getchar()) != '\n' && c !=EOF);

			trial++;
		}
	}

	// after 3 invalid inputs we just return -1
	return -1;
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
		size_t i;
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
	size_t count = 0;
	long value;

	// Read the encrypted message from stdin
	while(1){
		// Try to read an Integer
		if(scanf("%ld", &value) != 1){
			return -1; // If the input is invalid
		}

		// Check for the end of the message
		if (value == 0) {
			cryp[count] = value;
			count++;
			break;
		}

		// Check if the array is full
		if(count >= elements){
			return -1;
		}

		// Store the value in the array
		cryp[count] = value;
		count++;
	}


	return count; // Return the number of values read
	

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
	// check the message is not empty
	if((msg != NULL) && (elements > 0) ){
		size_t i;
                for(i = 0; i <= elements; i++){
			if(msg[i]== '\0')
				break;
			printf("%c", msg[i]);
		}
		puts("");
                return i;
        }
        else {
                return -1;
        }
}

