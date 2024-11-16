/*
ASSIGNMENT: Encrypt a plaintext message with a given substitution cypher key.
ASSERT correct number and format of CLI arguments
- exactly 2 arguments
    Usage: ./substitution key
- 2nd arg, the cipher key, should be
    Key must contain 26 characters.
    Key must only contain alphabetic characters.
    Key must not contain repeated characters.
        - case insensitive
- return 1 on error
GET plaintext string
- preserve upper/lower casing of characters
- encipher string
OUTPUT ciphertext string
- last print a newline
- exit by returning `0` from `main`
OPTIONAL
- define my own strcasestr func, so I don't have to include GNU extensions
- compare perf of storing ciphertexted chars in an arry then printing, versus
  printing chars as they are encoded
*/
#define _GNU_SOURCE
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) {
    /*
    ASSERT correct number and format of CLI arguments
    - exactly 2 arguments
        Usage: ./substitution key
    - 2nd arg, the cipher key, should be
        Key must contain 26 characters.
        Key must only contain alphabetic characters.
        Key must not contain repeated characters.
            - case insensitive
    - return 1 on error
    */
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    if (strlen(key) != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // iterate through key, to check chars are alphabetic and don't contain dups
    char key_letters[27] = "";
    for (int i = 0, len = strlen(key); i < len; i++) {
        // printf("i: %i\n", i);
        // printf("key[i]: %c\n", key[i]);
        // printf("isalpha(key[i]): %i\n", isalpha(key[i]));
        if (!isalpha(key[i])) {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        // temp substring to search key_letters for duplicates
        char temp[2] = {toupper(key[i]), '\0'};
        if (strcasestr(key_letters, temp) != NULL) {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        key_letters[i] = key[i];
    }

    string plaintext = get_string("plaintext: ");

    // OUTPUT substituted cipher text, preserving case
    printf("ciphertext: ");
    char ciphertext[strlen(plaintext) + 1] = 
    for (int i = 0, len = strlen(plaintext), alpha_index; i <= len; i++) {
        // UPPERCASE: convert char to its ASCII dec code, then subtract 65 to get its alphabetic index
        //   From the array of the cipher key, print the value of the index
        if (isupper(plaintext[i])) {
            alpha_index = (int)plaintext[i] - 65;
            printf("%c", toupper(key[alpha_index]));
        }
        // LOWERCASE: convert char to its ASCII dec code, then subtract 97 to get its alphabetic index
        //   From the array of the cipher key, print the lowercased value of the index
        else if (islower(plaintext[i])) {
            alpha_index = (int)plaintext[i] - 97;
            printf("%c", tolower(key[alpha_index]));
        }
        else
            printf("%c", plaintext[i]);
    }
    printf("\n");
    return 0;
}

