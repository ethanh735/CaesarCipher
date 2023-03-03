//
// Created by Ethan Hoyt on 10/5/22.
//
#include <libc.h>
#include <stdio.h>
#include <string.h>

char* encryption(char mode, long shift, FILE* input) {
    // setup
    // size is max ushort size
    int size = 65535;
    char* buffer = malloc(size);
    unsigned long filesize;

    // get size of file, create message buffer
    if (input != stdin) {
        fseek(input, 0, SEEK_END);
        filesize = ftell(input);
        fseek(input, 0, SEEK_SET);

        fread(buffer, 1, filesize ,input);
    }
    else {
        do {
            printf("No input file given, enter message: ");
            fgets(buffer, size, stdin);
            filesize = strlen(buffer);
        }
        while (filesize >= size - 1);
    }

    // shift file contents
    for (long i = 0; i < filesize; i++) {
        // cast as long to prevent overflow while shifting
        long c = (long) buffer[i];
        if (mode == 'e') {
            // uppercase: 65 to 90
            if (c > 64 && c < 91) {
                c += (shift % 26);
                if (c >= 91) {
                    c -= 26;
                }
                else if (c <= 64) {
                    c += 26;
                }
            }
            // lowercase: 97 to 122
            else if (c > 96 && c < 123) {
                c += (shift % 26);
                if (c >= 123) {
                    c -= 26;
                }
                else if (c <= 96) {
                    c += 26;
                }
            }
        }
        else if (mode == 'd') {
            // uppercase: 65 to 90
            if (c > 64 && c < 91) {
                c -= (shift % 26);
                if (c >= 91) {
                    c -= 26;
                }
                else if (c <= 64) {
                    c += 26;
                }
            }
            // lowercase: 97 to 122
            else if (c > 96 && c < 123) {
                c -= (shift % 26);
                if (c >= 123) {
                    c -= 26;
                }
                else if (c <= 96) {
                    c += 26;
                }
            }
        }
        buffer[i] = (char) c;
    }
    return buffer;
}

// for every alphabetical char in the message, shift by n positions (circular)
// argv[1] is -e / -d, argv[2] is key, argv[3] is input file
int main(int argc, char* argv[]) {

    // setup
    char mode = 'e';
    long shift = 7;
    FILE* input = stdin;
    char* end;

    for (int i = 0; i < argc; i++) {
        // encrypt / decrypt
        if (strcmp(argv[i], "-d") == 0) {
            mode = 'd';
        }
        // shift amount
        long key = strtol(argv[i], &end, 10);
        if (key != 0) {
            shift = key;
        }
        // input file
        if (strlen(argv[i]) > 3 && strstr(argv[i], ".txt")) {
            input = fopen(argv[i], "r");
        }
    }
    printf("Encryption:\n%s", encryption(mode, shift, input));
    return 0;
}