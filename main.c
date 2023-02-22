//
// Created by Ethan Hoyt on 10/5/22.
//
#include <libc.h>
#include <stdio.h>
#include <string.h>

char* encryption(char mode, long shift, FILE* input) {
    // setup
    char* buffer;
    // printf("%ld\n",strlen(buffer));
    unsigned long filesize;

    // get size of file, create message buffer
    if (input != stdin) {
        fseek(input, 0, SEEK_END);
        filesize = ftell(input);
        // buffer = malloc(filesize);
        fseek(input, 0, SEEK_SET);

        fread(buffer, 1, filesize ,input);
    }
    else {
        printf("No input file given, enter message: ");
        scanf("%s", buffer);
        filesize = strlen(buffer);
    }
    // char* content[filesize] = buffer;
    int x = 30;
    char* content[x];
    if (filesize > x) {
        content[filesize];
    }
    printf("%ld\n", strlen(*content));

    // shift file contents
    for (long i = 0; i < filesize; i++) {
        if (mode == 'e') {
            // uppercase: 65 to 90
            if (buffer[i] > 64 && buffer[i] < 91) {
                buffer[i] += (shift % 26);
                if (buffer[i] >= 91) {
                    buffer[i] -= 26;
                }
                else if (buffer[i] <= 64) {
                    buffer[i] += 26;
                }
            }
            // lowercase: 97 to 122
            else if (buffer[i] > 96 && buffer[i] < 123) {
                buffer[i] += (shift % 26);
                if (buffer[i] >= 123) {
                    buffer[i] -= 26;
                }
                else if (buffer[i] <= 96) {
                    buffer[i] += 26;
                }
            }
        }
        else if (mode == 'd') {
            // uppercase: 65 to 90
            if (buffer[i] > 64 && buffer[i] < 91) {
                buffer[i] -= (shift % 26);
                if (buffer[i] >= 91) {
                    buffer[i] -= 26;
                }
                else if (buffer[i] <= 64) {
                    buffer[i] += 26;
                }
            }
            // lowercase: 97 to 122
            else if (buffer[i] > 96 && buffer[i] < 123) {
                buffer[i] -= (shift % 26);
                if (buffer[i] >= 123) {
                    buffer[i] -= 26;
                }
                else if (buffer[i] <= 96) {
                    buffer[i] += 26;
                }
            }
        }
        printf("%c\n", buffer[i]);
    }
    return buffer;
}

// for every alphabetical char in the message, shift by n positions (circular)
int main(int argc, char* argv[]) {
    // argv[1] is -e / -d, argv[2] is key, argv[3] is input file

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
    printf("Encryption: %s", encryption(mode, shift, input));
}