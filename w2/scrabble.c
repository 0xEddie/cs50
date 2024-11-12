#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_score(string);

int main(void)
{
    // prompt for 2 words, calculate their scrabble scores, then display winner
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int score1 = get_score(word1);
    int score2 = get_score(word2);

    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score2 > score1)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}

int get_score(string word)
{
    // for a given word, sum its scrabble score by iterating through the characters of the string,
    // ignoring non-alphabetic characters
    int score = 0;
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        char c = toupper(word[i]);
        if ((int) c >= 65 && (int) c <= 90)
        {
            switch (c)
            {
                case 'B':
                    score += 3;
                    break;
                case 'C':
                    score += 3;
                    break;
                case 'D':
                    score += 2;
                    break;
                case 'F':
                    score += 4;
                    break;
                case 'G':
                    score += 2;
                    break;
                case 'H':
                    score += 4;
                    break;
                case 'J':
                    score += 8;
                    break;
                case 'K':
                    score += 5;
                    break;
                case 'M':
                    score += 3;
                    break;
                case 'P':
                    score += 3;
                    break;
                case 'Q':
                    score += 10;
                    break;
                case 'V':
                    score += 4;
                    break;
                case 'W':
                    score += 4;
                    break;
                case 'X':
                    score += 8;
                    break;
                case 'Y':
                    score += 4;
                    break;
                case 'Z':
                    score += 10;
                    break;
                default:
                    score += 1;
                    break;
            }
        }
    }
    return score;
}

