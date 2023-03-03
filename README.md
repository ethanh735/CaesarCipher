# CaesarCipher

A Caesar Cipher that can encrypt and decrypt text, either from manual or file input, by shifting it a certain amount.

Written entirely in C23, and dependent on the libc, stdio, and string header files for its various usages of string handling and file I/O.

To use: 
1. Clone this repo and move to the CaesarCipher directory
2. compile main.c with gcc, clang, etc.
3. Execute the resulting output with any of three possible flags: encryption / decryption (-e / -d), the shift amount (any number), and / or a text file to read input from (name of file, without .txt)

Behaviors:
- All the flags can be either present or absent: each has a default behavior if a flag is unspecified.
- The shift amount cannot be 0: entering a flag of 0 will make the shift amount the default value of 7. A shift of 26 is effectively a shift of 0 though.
- There's a very tough tradeoff between the behaviors of pointers and arrays in C for input handling: these seem inherent to the language, and things like the inability for input container resizing is something that the cipher will likely have to live with due to the design decisions of the language.
