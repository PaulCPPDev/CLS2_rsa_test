/**
 * @file keygen.c
 * @ref BTS1230
 * @copyright Bern University of Applied Sciences, 2023. All rights reserved.
 *
 * @author Paul Holderbaum <paul.holderbaumondoua@students.bfh.ch>
 * @date 01.12.2023
 *
 * @brief RSA key generation module.
 *
 * This is the module that helps generate keys. It contains the
 * functions is_prime(), gcd(), modulus(), phi(), public_exponent(), private_exponent()
 */


#include <stdio.h>
#include <stddef.h>






/**
 * @brief Checks if a number is a prime number.
 *
 * This function checks if a number is a prime number. we only use small primes between 100 and 1000
 * Thus, the function also has to ensure that the number is 100 <= number <= 1000.
 * Furthermore, negative numbers are not allowed as well.
 *
 * @param The number you want to check if it is prime.
 * @return 1 if the number is prime, 0 if the number is not prime, 
 * −1 if the number is invalid or an error has occurred.
 */
int is_prime(int number){
        printf("is_prime()\n");
	return 1;
}







/**
 * @brief Calculates the gcd of 2 numbers.
 *
 * Computes the greatest common divisor of two numbers. 
 * It is an error if the numbers are equal or any of them is negative.
 *
 * @param 2 numbers of type long.
 * @return The greatest common divisor of the two arguments, or −1 in case of an error.
 */
long gcd(long a, long b){
	printf("gcd()\n");
	return 1;
}







/**
 * @brief Calculates the RSA modulus.
 *
 * Computes the RSA modulus needed for encryption and decryption. 
 * It is an error if any of the parameters is 0.
 *
 * @param 2 prime numbers of type int.
 * @return The RSA modulus n derived from p and q, or −1 in case of an error.
 */
long modulus(int p, int q){
	printf("modulus()\n");
	return 1;
}







/**
 * @brief Calculate the Euler's totient.
 *
 * Computes the Euler’s totient ϕ required for deriving the public and private key exponents. 
 * It is an error if any of the parameters is 0.
 *
 * @param 2 prime numbers of type int.
 * @return The Euler’s totient ϕ, derived from p and q, or −1 in case of an error.
 */
long phi(int p, int q){
	printf("phi()\n");
	return 1;
}






/**
 * @brief Generates the public key exponent.
 *
 * Generates a new, random public key exponent e, according to the RSA definition.
 *
 * @param The Euler's totient phi, of type long.
 * @return The public key exponent e, or −1 in case of an error.
 */
long public_exponent(long phi){
	printf("public_exponent()\n");
	return 1;
}







/**
 * @brief Generates the private key exponent.
 *
 * Computes the private key exponent d according to the RSA definition.
 *
 * @param the public exponent, and Euler's totient phi. Both of type long.
 * @return The private key exponent d, or −1 in case of an error.
 */
long private_exponent(long e, long phi){
	printf("private_exponent()\n");
	return 1;
}





