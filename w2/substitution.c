/*
ASSIGNMENT Encrypt a plaintext message using a substitution cypher key.
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
        printf("Usage: ./substitution key");
        return 1;
    }
    string key = argv[1];
    if (strlen(key) != 26) {
        printf("Key must contain 26 characters.");
        return 1;
    }
    // iterate through key, to check chars are alphabetic and don't contain dups
    char key_letters[27] = "";
    for (int i = 0, len = strlen(key); i <= len; i++) {
        if (!isalpha(key[i])) {
            printf("Key must only contain alphabetic characters");
            return 1;
        }
        // temp substring to search key_letters for duplicates
        char temp[2] = {toupper(key[i]), '\0'};
        if (strcasestr(key_letters, temp) != NULL) {
            printf("Key must not contain repeated characters.");
            return 1;
        }
        key_letters[i] = key[i];
    }

    // if UPPERCASE: convert char to its ASCII dec code, then subtract 65 to get its alphabetic index
    //   from the array of the cipher key, print the value of the index
    // if LOWERCASE: convert char to its ASCII dec code, then subtract 97 to get its alphabetic index
    //   from the array of the cipher key, print the lowercased value of the index
}


