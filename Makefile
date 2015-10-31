CC = gcc
CFLAGS = -lm -lcrypto

encrypt0: encrypt0.c
	$(CC) encrypt0.c -o encrypt0 $(CFLAGS)