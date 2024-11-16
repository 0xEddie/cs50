#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/*
- CL index is an assessment of the reading level of a text
index = 0.0588 * L - 0.296 * S - 15.8
L = average number of letters per 100 words
S = average number of sentences per 100 words
Letters > Count number of uppercase and lowercase letters in a text
- use functions from `ctype.h` for assessing if a char is a letter
    - isalpha(char)
Words > Count number of spaces
- assume given text won't start or end with whitespace
Sentences > Count punctuation
- Any period, exclamation point, or question mark indicates a sentence
Output >
- round score to nearest whole number
- if index is below 1 > print "Before Grade 1"
- if index is above 16 > print "Grade 16+"
- else print "Grade <i>"
*/

int main(void)
{
    string text = get_string("Text: ");

    // count letters and words and sentences
    int letter_count = 0, word_count = 1, sentence_count = 0;
    char _char;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        _char = text[i];
        if (isalpha(_char))
            letter_count++;
        else if (isspace(_char))
            word_count++;
        else if (ispunct(_char))
        {
            switch (_char)
            {
                case '.':
                    sentence_count++;
                    break;
                case '!':
                    sentence_count++;
                    break;
                case '?':
                    sentence_count++;
                    break;
            }
        }
    }

    // calc avg num letters per 100 words
    float L = (float) letter_count / word_count * 100;
    // calc avg num sentences per 100 words
    float S = (float) sentence_count / word_count * 100;
    // calc Coleman-Liau index
    float cl_index = (0.0588 * L) - (0.296 * S) - 15.8;
    int rounded_cl_index = round(cl_index);

    // output CL index
    char output[20];
    if (rounded_cl_index < 1)
        strcpy(output, "Before Grade 1");
    else if (rounded_cl_index > 16)
        strcpy(output, "Grade 16+");
    else
        sprintf(output, "Grade %i", rounded_cl_index);
    printf("%s\n", output);
}

