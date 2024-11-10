#include <cs50.h>
#include <stdio.h>

int largest_coin(int);

int main(void)
{
    // get a valid amount of changed owed (in cents) from user
    int cents = 0;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 1);

    // subtract largest denomination of coin from changed owed until change == 0
    int rem = cents;
    int coins = 0;
    int coin = 0;
    do
    {
        coin = largest_coin(rem);
        rem -= coin;
        coins++;
    }
    while (rem > 0);
    printf("%i\n", coins);
}

int largest_coin(int change_owed)
{
    // returns value (in cents) of largest coin denomination that fits into change_owed
    if (change_owed >= 25)
        return 25;
    if (change_owed >= 10)
        return 10;
    if (change_owed >= 5)
        return 5;
    if (change_owed >= 1)
        return 1;
    else
        return 0;
}

