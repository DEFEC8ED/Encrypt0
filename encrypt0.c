#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <signal.h>

#include <openssl/evp.h>
#include <openssl/buffer.h>

#include "enc.h"
#include "colors.h"

#define SIZE 256
#define NEXT printf("\n"); /* to avoid maximum  mess :) */

/*** globals ***/

int dir;

/***************/

int main(int argc, char *argv[])
{
  int key, ans;
  char ch, c, a[1000];
  char *arr;
  const char *output;
  char string[SIZE];
  char base64[SIZE];
  char *xor_key;

  arr = a;

  FILE *fp1, *fp2; /* basically for the --Etx function */

  srand((unsigned int)time(0) + getpid()); /* changes the pass-gen immediately */
  
  signal(SIGINT, a_trap); // Trap mechanism for CTRL + C
  
  // Party can begin
  switch (argc) /* using the switch base on the number of arguements (easy to manage later on) */
    {
      
    case 1:
      
      printf("Too Little Arguments.\n");
      printf("Check %s-h%s, %s--help%s for the usage menu.\n", red, normal, red, normal);
      
      break;

    case 2:
      
      if ((strncmp(argv[1], "-h", 2) == 0) || (strncmp(argv[1], "--help", 6) == 0))
	{
	  help_info(); /* Displays the help page */
	}

      else
	{
	  printf("You mean the %s-h%s, %s--help%s commands?\n", red, normal, red, normal);
	}
      
      break;

    case 4:

      if ((strncmp(argv[1], "--Es", 5) == 0) && (strncmp(argv[2], "-sne", 5) == 0))
	{
	  system("clear"); /* basically clears the screen for more readability */

	  printf("Enter in the 'key' to shift: ");
	  scanf("%d", &key); /* basically a key is used to make the actual string shift (kind of a password) */

	  NEXT

	  printf("Do you want to shift encrypt backwards or forward:\n");
	  printf("Hit (1) for forward, Hit (-1) for backward: ");
	  scanf("%d", &dir);
	  
	  shift_encrypt(argv[3], key); /* brings up the shift_encrypt function from (enc.h) */

	  NEXT
	    
	  printf("Your new string is: %s\n", argv[3]);

	  }

      else if ((strncmp(argv[1], "--Es", 5) == 0) && (strncmp(argv[2], "-snd", 5) == 0))
	{
	  system("clear");

	  printf("Enter in the 'key' to shift: ");
	  scanf("%d", &key);

	  NEXT

	  printf("Do you want to shift encrypt backwards or forward:\n");
	  printf("Hit (1) for forward, Hit (-1) for backward: ");
	  scanf("%d", &dir);

	  shift_decrypt(argv[3], key);

	  NEXT

	  printf("The decrypted string is: %s\n", argv[3]);
	}

      else if ((strncmp(argv[1], "--Es", 5) == 0) && (strncmp(argv[2], "-sh", 4) == 0))
	{
	  system("clear");
	  
	  printf("String: %s\n", argv[3]);
	  
	  printf("Hexadecimal: ");

	  string_to_hex(argv[3]); /* Calls the hex_to_string function */
	}

      else if ((strncmp(argv[1], "--Es", 5) == 0) && strncmp(argv[2], "-db", 4) == 0)
	{
	  system("clear");

	  num_to_bin(argv[3]);
	  
	  NEXT
	}

      else if ((strncmp(argv[1], "--Es", 5) == 0) && (strncmp(argv[2], "-bd", 4) == 0))
	{
	  system("clear");

	  printf("The binary is: %s\n", argv[3]);

	  ans = bin_to_num(argv[3]);
	  
	  printf("The number is: %d\n", ans);
	}

      else if ((strncmp(argv[1], "--Es", 5) == 0) && (strncmp(argv[2], "-hs", 4) == 0))
	{
	  system("clear");
	  printf("Hexadecimal is: %s\n", argv[3]);

	  hex_to_string(argv[3]);  
	}

      else if ((strncmp(argv[1], "--Grs", 6) == 0) && (strncmp(argv[2], "-ul", 4) == 0))
	{
	  system("clear");
	  
	  gen_ul(argv[3], arr); /* (takes in an character pointer to print it later) generates upper and lower characters */

	  printf("The random string: %s\n", arr);
	}

      else if ((strncmp(argv[1], "--Grs", 6) == 0) && (strncmp(argv[2], "-uln", 5) == 0))
	{
	  system("clear");

	  gen_uln(argv[3], arr); /* generates upper + lower + number  */

	  printf("The random string: %s\n", arr);
	}

      else if ((strncmp(argv[1], "--Grs", 6) == 0) && (strncmp(argv[2], "-ulns", 6) == 0))
	{
	  system("clear");
	  
	  gen_ulns(argv[3], arr); /* generates upper + lower + number + special (try to use this for most security) */
	  
	  printf("The random string: %s\n", arr);
	}

      else if ((strncmp(argv[1], "--Es", 5) == 0) && (strncmp(argv[2], "-e64", 5) == 0))
	{
	  system("clear");

	  strncpy(string, argv[3], SIZE);

	  output = en_base64(string, strlen(string)); /* calls function which uses the openssl lib functions */

	  printf("String: %s\nBase64: %s\n", string, output);

	  NEXT
	}

      else if ((strncmp(argv[1], "--Es", 5) == 0) && (strncmp(argv[2], "-d64", 5) == 0))
	{
	  system("clear");

	  strncpy(base64, argv[3], SIZE); /* passing the command line arguement to base64[SIZE] */ 
	  
	  strcat(base64, "\n");

	  output = decode_base64(base64, strlen(base64)); /* calls function which uses the openssl lib functions */

	  printf("Base64: %sString: %s\n", base64, output);
	  
	  NEXT
	  
	}

      else if ((strncmp(argv[1], "--Es", 5) == 0) && (strncmp(argv[2], "-exor", 6) == 0))
	{
	  system("clear");	  

	  printf("Enter in a (number) |key|: ");
	  scanf("%s", xor_key);

	  encrypt_XOR_num(argv[3], xor_key); /* XOR works on the bits (1 + 1 = 0)(1 + 0 = 1)(0 + 1 = 1)(0 + 0 = 0) */
	  
	  NEXT

	  printf("The encrypted string: %s\n", argv[3]);
	}

      else if ((strncmp(argv[1], "--Es", 5) == 0) && (strncmp(argv[2], "-dxor", 6) == 0))
	{
	  system("clear");

	  printf("Enter your |(number key)| to decrypt: ");
	  scanf("%s", xor_key);

	  NEXT
	  
	  decrypt_XOR_num(argv[3], xor_key);

	  NEXT
	}
      
      break;

    case 5:
      
      if ((strncmp(argv[1], "--Etx", 6) == 0) && (strncmp(argv[2], "-sne", 5) == 0))
	{
	  system("clear");

	  fp1 = fopen(argv[3], "w");

	  if (fp1 == NULL) /* file pointers return NULL */
	    {
	      printf("Error in opening files!\n");
	      exit(0);
	    }

	  printf("Input information into %s:\n", argv[3]);
	  printf("On [linux] machines hit (CTRL-D) to [TERMINATE] writing.\n");
	  
	  NEXT

	  while ((c = getchar()) != EOF)
	    {
	      putc(c, fp1);
	    }

	  fclose(fp1);
	  
	  NEXT

	  printf("Successfully written info to %s\n", argv[3]);

	  printf("Enter in the 'key' to shift: ");
	  scanf("%d", &key);
	  
	  NEXT

	  printf("Do you want to shift encrypt backwards or forward:\n");
	  printf("Hit (1) for forward, Hit (-1) for backward: ");
	  scanf("%d", &dir);

	  NEXT

	  fp1 = fopen(argv[3], "r");
	  fp2 = fopen(argv[4], "w");
	  
	  if (fp1 == NULL || fp2 == NULL)
	    {
	      printf("Error in opening files!\n");
	      exit(0);
	    }
	  
	  file_shift_encrypt(fp1, fp2, key); /* Same type of encryption in the first option (-sn) but implemented on files */

	  fclose(fp1);
	  fclose(fp2);

	  printf("Message is passed to %s [Success in encrypting]\n", argv[4]);
	}

      else if ((strncmp(argv[1], "--Etx", 6) == 0) && (strncmp(argv[2], "-snd", 5) == 0))
	{
	  system("clear");

	  fp1 = fopen(argv[3], "r"); /* read mode */
	  fp2 = fopen(argv[4], "w"); /* write mode */
	  
	  if (fp1 == NULL || fp2 == NULL)
	    {
	      printf("Error in opening the (encrypted file) or error in opening (ouput file).\n");
	      exit(0);
	    }
	  
	  printf("Enter in the 'key' to decrypt the file: ");
	  scanf("%d", &key);

	  printf("Do you want to shift decrypt backwards or forward:\n");
	  printf("Hit (1) for forward, Hit (-1) for backward: "); /* means ----> shift or <----- shift :)*/
	  scanf("%d", &dir);

	  NEXT

	  file_shift_decrypt(fp1, fp2, key);

	  fclose(fp1);
	  fclose(fp2);
	  
	  printf("%s has the contents of decrypted information [Sucess in decrypting].\n", argv[4]);
	  
	}
      
      break;
      
    default:
      
      printf("You have entered in a wrong command line function.\n");
      break;
      
    }
  
  

  return 0;
}
