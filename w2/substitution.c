#include <cs50.h>
#include <stdio.h>

/*
ASSERT correct number and format of CLI arguments
- exactly 2 arguments
    Usage: ./substitution key
- 2nd arg, the cipher key, should be
    Key must contain 26 characters.
    Key must only contain alphabetic characters.
    Key must not contain repeated characters.
- return 1 on error
GET plaintext string
- preserve upper/lower casing of characters
- encipher string
OUTPUT ciphertext string
- last print a newline
- exit by returning `0` from `main`
*/

int main(void) {
    // assert correct number and format of cli args
    // I should compare performance difference of storing ciphertexted chars in an arry then printing, with just printing chars as they are encoded
    // if UPPERCASE: convert char to its ASCII dec code, then subtract 65 to get its index in an array of the alphabet
    // from the array of the cipher key, print the value of the index
    // if LOWERCASE: convert char to its ASCII dec code, then subtract 97 to get its index in an array of the alphabet
    // from the array of the cipher key, print the lowercased value of the index
}

