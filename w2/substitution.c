/*
ASSIGNMENT: Encrypt a plaintext message with a given substitution cypher key.
ASSERT correct number and format of CLI arguments
- exactly 2 arguments
- 2nd arg, the cipher key
    - contain 26 characters
    - only contain alphabetic characters
    - not contain repeated characters
    - case insensitive
- return 1 on error
GET plaintext string
- preserve upper/lower casing of characters
- encode string
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

int main(int argc, string argv[])
{
    /*
    ASSERT correct number and format of CLI arguments
    - exactly 2 arguments
        Usage: ./substitution key
    - 2nd arg, the cipher key reqs:
        Key must contain 26 characters.
        Key must only contain alphabetic characters.
        Key must not contain repeated characters.
            - case insensitive
    - return 1 on error
    */
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key_raw = argv[1];
    if (strlen(key_raw) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // iterate through key, to check chars are alphabetic and don't contain dups
    // store key chars as uppercase, for easier enciphering of plaintext
    char key[27] = "";
    for (int i = 0, len = strlen(key_raw); i < len; i++)
    {
        if (!isalpha(key_raw[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        // temp substring to search key for duplicates
        char temp[2] = {toupper(key_raw[i]), '\0'};
        if (strcasestr(key, temp) != NULL)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        key[i] = toupper(key_raw[i]);
    }

    string plaintext = get_string("plaintext: ");

    // OUTPUT substituted cipher text, preserving case
    /*
    Since we are only processing one string (and not combining a dynamic number of strings),
    manually encipher characters to an output array, then print the array.
    - don't use `strcat` -> is O(n^2) runtime in a forloop
    - save chars to array -> only one syscall to print, intstead of one print syscall per char
    */
    int text_length = strlen(plaintext) + 1;
    char ciphertext[text_length];
    char c;
    for (int i = 0, len = strlen(plaintext), alpha_index; i < len; i++)
    {
        // encipher alphabetical characters
        if (isalpha(plaintext[i]))
        {
            alpha_index = (int) toupper(plaintext[i]) - 'A';
            c = isupper(plaintext[i]) ? key[alpha_index] : tolower(key[alpha_index]);
            ciphertext[i] = c;
        }
        // pass nonalphabetic characters directly
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[text_length - 1] = '\0';

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

