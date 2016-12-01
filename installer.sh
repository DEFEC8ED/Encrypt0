#!/bin/bash

if [[ $EUID -ne 0 ]]; then
	echo "You must be root for run this script!" 2>&1 | grep "root" --color
	exit 1
fi

echo "[+] Installing libssl-dev package..." | grep "+" --color
sudo apt-get install libssl-dev

echo "[+] Compiling program..." | grep "+" --color
gcc encrypt0.c -o encrypt0 -lm -lcrypto

echo "[+] Program prepared. Enjoy it!" | grep "+" --color
