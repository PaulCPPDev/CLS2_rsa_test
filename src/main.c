/**
 * @file main.c
 * @ref BTS1230
 * @copyright Bern University of Applied Sciences, 2023. All rights reserved.
 *
 * @author Ait Ouhamou Yassin <yassin.aitouhamou@students.bfh.ch>
 * @date 19.12.2023
 *
 * @brief  (main module). This code is a modified version of the template from 
 * Pascal Mainini <pascal.mainini@bfh.ch>
 *
 * This is the main module of the modular programming example. It contains the
 * main()-function, and the logic used for the main menu. 
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
#include <stdbool.h>

#define MSG_SIZE 100

enum menu_entry_ids { GENERATE_KEYS, ENCRYPT_MESSAGE, DECRYPT_MESSAGE, RIDDLE, QUIT, NUM_ENTRIES };
static char const *const menu_entries[] = {[GENERATE_KEYS] = "Generate keys",
					   [ENCRYPT_MESSAGE] = "Encrypt a message",
                                           [DECRYPT_MESSAGE] = "Decrypt a message",
                                           [RIDDLE] = "Riddle Game",
                                           [QUIT] = "Quit"};

static void display_menu() {
  puts("*****************************************");
  puts("                ENIGMA");
  puts("*****************************************");

  for (enum menu_entry_ids id = 1; id - 1 < NUM_ENTRIES; ++id) {
    printf(" %3d : %s\n", id, menu_entries[id - 1]);
  }
}

static enum menu_entry_ids read_choice() {
  enum menu_entry_ids choice = -1;

  do {
    display_menu();
    printf("\nWhat is your choice? : ");
    if (1 != scanf(" %d", (int *)&choice)) {
      getchar();
      continue;
    }
    choice--;
  } while (choice < 0 || choice >= NUM_ENTRIES);

  return choice;
}

static void say(char const *message) { printf("\n%s\n\n", message); }






int main() {
  printf("\033c"); // clear terminal

  for (bool exit = false; !exit;) {
    switch (read_choice()) {
    case GENERATE_KEYS:
      say("Generate Public and Private Keys!");
      
      int p, q = 0;
      // input for p
      bool p_is_valid = false;
      do{
      	printf("Enter a Prime number p in the range\n100 <= p <= 1000");
      	p = read_number();
      	int p_prime = is_prime(p);
      	if(p_prime == -1)
      		printf("Invalid Input try again\n\n");
      	else if(p_prime == 0)
      		printf("The number is not prime try again\n\n");
      	else 
      		p_is_valid = false;
	} while(p_is_valid);   
      //check p is valid
      if(p == -1 || ( is_prime(p) != 1) )
      	break;
      	
      // input for q
      bool q_is_valid = false;
      do{
      	printf("\nEnter a Prime number q in the range\n100 <= q <= 1000");
      	q = read_number();
      	int q_prime = is_prime(q);
      	if(q_prime == -1)
      		printf("Invalid Input try again\n");
      	else if(q_prime == 0)
      		printf("The number is not prime try again\n");
      	else 
      		q_is_valid = false;
	} while(q_is_valid);	
      //check q is valid
      if(q == -1 || ( is_prime(q) != 1) )
      	break;
	   
      // Calculate n
      long n = 0;
      n = modulus(p,q);

      // Calculate phi
      long phi_euler = 0;
      phi_euler = phi(p,q);
      printf("\nphi(n) = %ld\n", phi_euler);

      // Generate public exponent
      long e = 0;
      e = public_exponent(phi_euler);
      printf("\nThe public key (n,e) = ( %ld , %ld )\n\n", n, e);
      
      // Generate private exponent
      long private_key = private_exponent(e,phi_euler);
      printf("\n*******************\nThe private key d = %ld\n*******************\n\n", private_key);
      puts("");
      break;


    case ENCRYPT_MESSAGE:
    	say("Encrypt a Message!");
    	
    	// Enter your public exponent
    	long pub_expo = 0;
    	printf("\nEnter your Public Exponent e ");
    	pub_expo = read_number();
    	// check e is valid
    	if(pub_expo == -1){
    		puts("Invalid input try again.");
    		break;
    	}
    	
    	// Enter the RSA modulus n
    	long modulus = 0;
    	printf("\nEnter the RSA modulus n ");
    	modulus = read_number();
    	// check modulus is valid
    	if(modulus == -1){
    		puts("Invalid input try again.");
    		break;
    	}
    
    
    	// Enter message to be encrypted
    	//#define MSG_SIZE 100
    	char message[MSG_SIZE];
    	
    	printf("\nEnter a message to be encrypted:\n");
	
	int msg_size = 0;
	
	if(scanf(" ")){};
	if(scanf("%[^\n]", message) >= 1)
		msg_size = strlen(message) +1;
		
	printf("\nmsg_size = %d  message = %s\n",msg_size, message);
	long cryp[MSG_SIZE];
	int was_encrypted = encrypt(pub_expo, modulus, message, cryp, msg_size);
	
	if(!was_encrypted){
		printf("\nError Encrypting the message\n");
	}
	else{
		printf("\nThe encrypted message is: \n");
		int num_written= display_cryp(cryp, msg_size);
		printf("\nNumber of characters Encrypted = %d\n", num_written);
		printf("\n");
	}
    	break;
    	
    case DECRYPT_MESSAGE:
      say("Decrypt a Message!");
      
      long d = 1;
      long dmsg_size = 0;
      
      // Enter the RSA modulus n
      long decryp_modulus = 0;
      printf("\nEnter the RSA modulus n: ");
      if(scanf("%ld", &decryp_modulus)){};
      
      // Enter the private key
      printf("Enter the decryption key d: ");
      if(scanf("%ld", &d)){};
      
      //Enter the length of the message to be decrypted
      printf("Enter the length of the encrypted message: ");
      if(scanf("%ld", &dmsg_size)){};
     
      // read the encrypted message
      long * crypted_msg = (long *) malloc(dmsg_size * sizeof(long));
      char * decrypted_msg = (char *) malloc(dmsg_size * sizeof(char));
      printf("Enter the encrypted message:\n");
      long num_values = read_cryp(crypted_msg, dmsg_size);

      
      //decrypt the message
      // problem here shows garbage values don't know why
      long values_decrypted = decrypt(d, decryp_modulus, crypted_msg, decrypted_msg, num_values);
      printf("\nnumber of values decrypted = %ld\n", values_decrypted);      
      
      //display the decrypted message
      puts("");
      display_msg(decrypted_msg,dmsg_size);
      puts("");
      
      // deallocate the memory
      free(crypted_msg);
      free(decrypted_msg);
      break;
      
    
    case RIDDLE:
    	say("Riddle Game!");
    	say("In this game we give you a question and it's encrypted answer. (HINT) use option 3 of the user menu to find the correct answer");
    	char questions[10][100] = {"Why do programmers prefer dark mode?",
    					 "Why did the computer catch a cold?", 
    					 "How do you comfort a JavaScript bug?", 
    					 "Why do programmers prefer iOS development?",
    					 "Why do programmers prefer nature?",
    					 "How many programmers does it take to change a light bulb?",
    					 "Why was the math book sad?",
    					 "Why do Java developers wear glasses?",
    					 "How do you generate a random string?",
    					 "Why did the programmer quit his job?"
    					};
    	/*char answers[10][65] ={"Because the light attracts bugs.", 
    					"It left its Windows open." , 
    					"You console it.", 
    					"Because it's the only place where Hello World! costs money.",
    					"It has the best syntax trees.",
    					"None. It's a hardware problem.",
    					"Because it had too many problems.",
    					"Because they don't see sharp.",
    					"Put a Windows user in front of Vim and tell them to exit.",
    					"He didn't get arrays."
    					 };*/
    	long encryp_answer[10][65]={
    					{551569, 825107, 144633, 535425, 432843, 647094, 825107, 953036, 205694, 450036, 825107, 953036, 450376, 775411, 347790, 450036, 205694, 953036, 535425, 205694, 205694, 641064, 535425, 144633, 205694, 647094, 953036, 75746, 432843, 347790, 647094, 836354, 0},
    					{665781, 612423, 538508, 428627, 26526, 60985, 612423, 538508, 671884, 612423, 132306, 538508, 906533, 671884, 616990, 223368, 524236, 479978, 132306, 538508, 524236, 656178, 26526, 616990, 852142, 0},
    					{191963, 347803, 289769, 437409, 135878, 347803, 200115, 389733, 347803, 92112, 165496, 437409, 366245, 104949, 460337, 0},
    					{11711, 18508, 23284, 1597, 43321, 24292, 18508, 17632, 3740, 37779, 44506, 24292, 17632, 37779, 44188, 18508, 17632, 30708, 12687, 2816, 39173, 17632, 21660, 2816, 1597, 23284, 18508, 17632, 39279, 44188, 18508, 21898, 18508, 17632, 48212, 18508, 2816, 2816, 30708, 17632, 20873, 30708, 21898, 2816, 38794, 13521, 17632, 23284, 30708, 24292, 37779, 24292, 17632, 11072, 30708, 12687, 18508, 39173, 34149, 0},
    					{48626, 93650, 101822, 57063, 35191, 78011, 101822, 93650, 57063, 35063, 101822, 48940, 35063, 78011, 93650, 101822, 78011, 79854, 62161, 93650, 35191, 97694, 101822, 93650, 26080, 35063, 35063, 78011, 24560, 0},
    					{1198, 538, 10302, 3205, 5000, 1767, 649, 1863, 7402, 9149, 1767, 4994, 1767, 9065, 4994, 8191, 1867, 6831, 4994, 8191, 3205, 1767, 7379, 8191, 538, 10870, 9524, 3205, 9220, 5000, 0},
    					{3325, 3333, 678, 9360, 9472, 4458, 3333, 877, 5487, 2817, 877, 3880, 9360, 3029, 877, 2817, 9888, 9888, 877, 1361, 9360, 6713, 6982, 877, 6732, 3498, 9888, 8846, 3532, 3333, 1361, 4458, 8761, 0},
    					{4692, 17271, 23147, 2605, 15288, 7034, 17271, 24685, 26927, 2597, 17271, 26282, 24685, 10301, 4353, 19021, 26102, 26927, 24685, 7034, 17271, 17271, 24685, 7034, 2597, 2605, 8984, 25627, 23619, 0},
    					{2099, 1006, 10309, 7329, 6848, 7329, 791, 1636, 1444, 9695, 4555, 10127, 6986, 7329, 1006, 6986, 9797, 4895, 7329, 1636, 1444, 7329, 102, 4895, 4555, 1444, 10309, 7329, 4555, 102, 7329, 8275, 1636, 3452, 7329, 6848, 1444, 9695, 7329, 10309, 9797, 6640, 6640, 7329, 10309, 7108, 9797, 3452, 7329, 10309, 4555, 7329, 9797, 3055, 1636, 10309, 9326, 0},
    					{1302, 6060, 2165, 6362, 326, 6362, 6029, 3365, 8333, 2165, 4429, 6060, 8333, 2165, 3815, 1726, 1726, 3815, 2170, 9511, 880, 0}
    			};
    	long rsa_modulus[10] = {988027, 988027, 494059, 57371, 102691,11021, 10807, 31007, 10403, 10403};
    	//long public_key[10] = {545201, 721703, 261985, 28055, 18859, 10211, 7591, 10889,  113, 143};
    	long decryption_key[10] = {316961, 93767, 225129, 31559, 48283, 1799, 8511, 8009, 5777, 5207};
    	
    	long ans_length[10]= {33,26, 16, 60, 30, 31, 34, 30, 58, 22};
    	
    	int q_num  = 0;
    	printf("Enter a number between 0 and 9\n");
	if(scanf("%d", &q_num) != 1){
		puts("Invalid Input try again \n\n");
		while(getchar() != '\n'); // clear the Input buffer
		break;
	}; 
	if(q_num <0 || q_num>9){
		puts("Out of range\n\n");
		break;
	}   	
    	printf("\nmodulus n = %ld \t private key d = %ld \t message length = %ld\n\n", rsa_modulus[q_num], decryption_key[q_num], ans_length[q_num]);
    	if(display_cryp(encryp_answer[q_num], ans_length[q_num]) == -1){
		break;
	}
	
    	printf("\n\n%s \n\n",questions[q_num]);
	
    	puts("\n\n");
    	break;

    case QUIT:
      puts("Good bye!");
      exit = true;
      break;

    default:
      break;
    }
  }
}

