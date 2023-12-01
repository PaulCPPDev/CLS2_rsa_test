#ifndef KEYGEN_H
#define KEYGEN_H



int is_prime(int number);

long gcd(long a, long b);

long modulus(int p, int q);

long phi(int p, int q);

long public_exponent(long phi);

long private_exponent(long e, long phi);


#endif


