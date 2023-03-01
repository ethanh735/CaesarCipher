# CaesarCipher

A Caesar Cipher that can encrypt and decrypt text, either from manual or file input, by shifting it a certain amount.

Written entirely in C23, and dependent on the libc, stdio, and string header files for its various usages of string handling and file I/O.

To use: 
1. Clone this repo and move to the CaesarCipher directory
2. compile main.c with gcc, clang, etc.
3. Execute the resulting output with any of three possible flags: encryption / decryption (-e / -d), the shift amount (any number), and / or a text file to read input from (name of file, without .txt)
