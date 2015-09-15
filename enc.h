/********************************************/
/****** Designed by Zapchast and Sunrix *****/
/********************************************/

/* Compile (gcc -o encrypt0 encrypt0.c -lm) */
/* run in (terminal/console) --> [./encrypt] with whatever option you want */

extern int dir;
/******************************************************************/
void help_info(void)
{
  system("clear");
  
  printf(" _____                             _    ___ \n");
  printf("| ____|_ __   ___ _ __ _   _ _ __ | |_ / _ \\ \n");
  printf("|  _| | '_ \\ / __| '__| | | | '_ \\| __| | | |\n");
  printf("| |___| | | | (__| |  | |_| | |_) | |_| |_| |\n");
  printf("|_____|_| |_|\\___|_|   \\__, | .__/ \\__|\\___/ \n");
  printf("                       |___/|_| \n\n");
 

  printf("\n\t\t[E n c r y t 0] (v1.0)\n\n");
  printf("Designed by: Zapchast & Sunrix\n\n");
  
  printf("Usage: ./encrypt0 [Choice Main] [Es-Options] [String, intergers, Encrypted String]\n");
  printf("Usage: ./encrypt0 [Choice Main] [Etx- Options] [source.txt] [final.txt]\n");
  printf("Usage: ./encrypt0 [Choice Main] [Grs- Options] [Length]\n\n");
  
  printf("Help:\n");
  
  printf("\t|MAIN|\n\n");

  printf("\t--Es [Encrypt strings]\n");
  printf("\t--Etx [Encrypt Text Documents]\n");
  printf("\t--Grs [Generate Random Strings]\n\n");

  printf("\t|--Es OPTIONS|\n\n");

  printf("\t-sne [Shift By (N) Encryption]\n"); //done 
  printf("\t-snd [Shift By (N) Decryption]\n"); // done
  printf("\t-exor [XOR Encryption]\n"); // done
  printf("\t-dxor [XOR Decryption]\n"); // done
  printf("\t-sh [String to Hexadecimal]\n"); // done
  printf("\t-hs [Hexadecimal to String]\n"); // under progress
  printf("\t-e64 [Base 64 Encoding]\n"); // done
  printf("\t-d64 [Base 64 Decoding]\n"); // done
  printf("\t-db [Decimal to Binay]\n"); // done
  printf("\t-bd [Binary to Decimal]\n\n"); // done

  printf("\t|--Etx OPTIONS|\n\n");

  printf("\t-sne [Shift By (N) Encryption]------> -sne[File for Shift By (N) Encryption]\n"); //done
  printf("\t-snd [Shift By (N) Decryption]------> -snd[File for Shift By (N) Decryption]\n\n");  //done
  
  printf("\t|--Grs OPTIONS]\n\n");

  printf("\t-ul [Generate random string (Upper + Lower )]\n"); // done
  printf("\t-uln [Generate random string (Upper + Lower + Numbers)]\n"); // done
  printf("\t-ulns [Generate random string (Upper + Lower + Numbers + Special Chars)]\n\n"); // done

  exit(0);
}
/**************************************************************/
void shift_encrypt(char *str, int k)
{
  int i;
  
  if (dir > 0)
    {
      for (i = 0; str[i] != '\0'; i++)
	{
	  str[i] = str[i] + k;
	  
	  if (str[i] < 33 || str[i] > 126)
	    {
	      printf("\nKey is too big!(Unable to encrypt)\n");
	      printf("Try a smaller key...\n");
	      exit(0);
	    }
	}

      str[i] = '\0';

      
    }

  else if (dir < 0)
    {
      for (i = 0; str[i] != '\0'; i++)
	{
	  str[i] = str[i] - k;

	  if (str[i] < 33 || str[i] > 126)
	    {
	      printf("Key is too small!(Unable to encrypt)\n");
	      printf("Try a bigger key...\n");
	      exit(0);
	    }
	}

      str[i] = '\0';
      
      
    }

  else
    {
      printf("Error in encrypting!\n");
      exit(0);
    }

}
/*******************************************/
void shift_decrypt(char *str1, int k)
{
  int i;

  if (dir > 0)
    {
      for (i = 0; str1[i] != '\0'; i++)
	{
	  str1[i] = str1[i] + k;

	  if (str1[i] < 33 || str1[i] > 126)
	    {
	      printf("Can't print the text!.\n");
	      exit(0);
	    }
	}

      str1[i] = '\0';
    }

  else if (dir < 0)
    {
      for (i = 0; str1[i] != '\0'; i++)
	{
	  str1[i] = str1[i] - k;

	  if (str1[i] < 33 || str1[i] > 126)
	    {
	      printf("Can't print the text!.\n");
	      exit(0);
	    }
	}

      str1[i] = '\0';
    }

  else
    {
      printf("Error in decrypting...\n");
      exit(0);
    }
}
/********************************/
void string_to_hex(char *str)
{
  int i;

  for (i = 0; str[i] != '\0'; i++)
    {
      
      
      printf("0x%x ", str[i]);
    }

  printf("\n");

  str[i] = '\0';
}
/***************************************/
void num_to_bin(char *string)
{
  int arr[100];

  int num, i, j, temp;

  num = atoi(string);

  temp = num;

  if (num == 0)
    {
      printf("It's not an interger!\n");
      printf("Please input in an interger...\n");
      exit(0);
    }
  
  i = j = 0;

  while (num != 0)
    {
      arr[i] = num % 2;
      i++;
      j++;
      
      num /= 2;
    }
  
  j -= 1;
  i -= 1;

  printf("The number: %d\n", temp);
  printf("The binary: ");

  for (i = j; i >= 0; i--)
    {
      printf("%d", arr[i]);
    }
  
}
/***************************************************/
void file_shift_encrypt(FILE *p1, FILE *p2, int k)
{
  int c;

  if (dir > 0)
    {
      while ((c = getc(p1)) != EOF)
	{
	  if (c == ' ')
	    {
	      continue;
	    }
	  
	  c += k;

	  putc(c, p2);

	  if (c < 33 || c > 126)
	    {
	      printf("\nKey is too big!(Unable to encrypt)\n");
	      printf("Try a smaller key...\n");
	      exit(0);
	    }
	}
    }

  else if (dir < 0)
    {
      while ((c = getc(p1)) != EOF)
	{
	  if (c == ' ')
	    {
	      continue;
	    }
	  
	  c -= k;

	  putc(c, p2);

	  if (c < 33 || c > 126)
	    {
	      printf("\nKey is too small!(Unable to encrypt)\n");
	      printf("Try a bigger key...\n");
	      exit(0);
	    }
	}
    }

  else
    {
      printf("Error in encrypting...\n");
      exit(0);
    }

}
/*********************************************/
int bin_to_num(char *str)
{
  int num = atoi(str);
  int i, temp, total;

  total = 0;

  if (num == 0)
    {
      printf("The input was not an interger...\n");
      printf("Please input in an interger.\n");
      exit(0);
    }
  
  /* Repeated division - by - 2 method */

  i = 0;

  while (num != 0)
    {
      temp = num % 10;
      
      if ((temp < 0) || (temp > 1))
	{
	  printf("Not a binay number!\n");
	  exit(0);
	}

      if (temp == 1)
	{
	  total = total + pow(2, i);
	}
      
      num /= 10;
      i++;
    }
  
  return total;
}
/*******************************************************/
void gen_ul(char *str, char *ran)
{
  int num, i;
  char *ch = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

  num = atoi(str);

  if (num <= 0)
    {
      printf("Please enter in a length!\n");
      exit(0);
    }
  
  for (i = 0; i < num; i++)
    {
      ran[i] = ch[rand() % 48 + 1];
    }
 
  ran[i] = '\0';
}
/*********************************************************/
void gen_uln(char *str, char *ran)
{
  int num, i;
  char *ch = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  
  num = atoi(str);

  if (num <= 0)
    {
      printf("Please enter in a length!\n");
      exit(0);
    }
  
  for (i = 0; i < num; i++)
    {
      ran[i] = ch[rand() % 58 + 1];
    }

  ran[i] = '\0';
}
/********************************************************/
void gen_ulns(char *str, char *ran)
{
  int num, i;
  char *ch = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
  
  num = atoi(str);

  if (num <= 0)
    {
      printf("Please enter in a length!\n");
      exit(0);
    }
  
  for (i = 0; i < num; i++)
    {
      ran[i] = ch[rand() % 70 + 1];
    }

  ran[i] = '\0';

}

char *en_base64(const char *input, int length)
{
  BIO *bmem, *b64;
  BUF_MEM *bptr;

  b64 = BIO_new(BIO_f_base64());
  bmem = BIO_new(BIO_s_mem());
  b64 = BIO_push(b64, bmem);

  BIO_write(b64, input, length);
  BIO_flush(b64);
  BIO_get_mem_ptr(b64, &bptr);

  char *buff = (char *)malloc(bptr->length);
	
  memcpy(buff, bptr->data, bptr->length-1);
  buff[bptr->length-1] = 0;

  BIO_free_all(b64);

  return buff;
	
  free(buff);
}

char *decode_base64(unsigned char *input, int length)
{
  BIO *b64, *bmem;

  char *buffer = (char *)malloc(length);
  memset(buffer, 0, length);

  b64 = BIO_new(BIO_f_base64());
  bmem = BIO_new_mem_buf(input, length);
  bmem = BIO_push(b64, bmem);

  BIO_read(bmem, buffer, length);

  BIO_free_all(bmem);

  return buffer;
}

void encrypt_XOR_num(char *str, char *key)
{
  int i, num;
  int len1 = strlen(str);
  int len2 = strlen(key);
  
  num = atoi(key);

  if (num <= 0)
    {
      printf("Only number keys!\n");
      exit(0);
    }

  if (len1 != len2) /* more secure as key needs to be same length to string */
    {
      printf("Key and string must be the same length!\n");
      exit(0);
    }

  for (i = 0; i < strlen(str); i++)
    {
      str[i] = str[i] ^ key[i];
      
      if (str[i] < 33 || str[i] > 126)
	{
	  printf("Please try a different key!\n");
	  exit(0);
	}
    }

  str[i] = '\0';
  
}

void decrypt_XOR_num(char *str, char *key)
{
  int i, num;
  int len1 = strlen(str);
  int len2 = strlen(key);
  
  num = atoi(key);

  if (num <= 0)
    {
      printf("Only positive number keys!\n");
      exit(0);
    }
  
  if (len1 != len2)
    {
      printf("Key and string must be the same length!\n");
      exit(0);
    }

  for (i = 0; i < strlen(str); i++)
    {
      str[i] = str[i] ^ key[i];
      
      if (str[i] < 33 || str[i] > 126)
	{
	  printf("Please try a different key!\n");
	  exit(0);
	}
    }

  str[i] = '\0';
  
  printf("Hope this is your decrypted string: [%s].\n", str);
  printf("If not... you might have entered the wrong key.\n");

}

void file_shift_decrypt(FILE *p1, FILE *p2, int k)
{
  int ch;

  if (dir > 0)
    {
      while ((ch = getc(p1)) != EOF)
	{
	  ch += k;

	  putc(ch, p2);
	  
	  if (ch < 33 || ch > 126)
	    {
	      printf("Can't decrypt it.\n");
	      exit(0);
	    }
	}
    }

  else if (dir < 0)
    {
      while ((ch = getc(p1)) != EOF)
	{
	  ch -= k;

	  putc(ch, p2);
	  
	  if (ch < 33 || ch > 126)
	    {
	      printf("Can't decrypt it.\n");
	      exit(0);
	    }
	}
    }

  else
    {
      printf("Error in decrypting...\n");
      exit(0);
    }
}

void a_trap(int signum)
{
  printf("\n[!] CTRL + C detected. I'm shutting down now.\n");
  exit(0);
}
