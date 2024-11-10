#include <cs50.h>
#include <stdio.h>

int count_digits(long);
int add_digits(int);

int main(void)
{
    bool checksum_isvalid = false;
    int amex_length = 15;
    int mc_length = 16;
    int visa_length1 = 13;
    int visa_length2 = 16;
    long card_number = get_long("Number: ");
    int card_number_length = count_digits(card_number);

    // early return if number is more than 16 digits or less than 13 digits
    if (card_number_length > 16 || card_number_length < 13)
    {
        printf("INVALID\n");
        return 0;
    }

    // calculate checksum of Luhn's algorithm to see if card number is valid
    int sum = 0;
    long rem = card_number;
    int first_digits;
    for (int i = 0; i < card_number_length; i++)
    {
        if (i % 2 == 0)
            sum += rem % 10;
        else
            sum += add_digits(rem % 10 * 2);

        // save first two digits of credit card number
        if (i == card_number_length - 2)
            first_digits = rem;
        rem /= 10;
    }
    if (sum % 10 == 0)
        checksum_isvalid = true;

    if (!checksum_isvalid)
    {
        printf("INVALID\n");
        return 0;
    }
    if (card_number_length == amex_length && (first_digits == 34 || first_digits == 37))
    {
        printf("AMEX\n");
        return 0;
    }
    else if (card_number_length == mc_length &&
             (first_digits == 51 || first_digits == 52 || first_digits == 53 ||
              first_digits == 54 || first_digits == 55))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else if ((card_number_length == visa_length1 || card_number_length == visa_length2) &&
             first_digits / 10 == 4)
    {
        printf("VISA\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

int count_digits(long number)
{
    // recursive function to calculate number of digits in a given long
    // exit case => only one number remaining
    if (number < 10)
        return 1;
    else
        return (1 + count_digits(number / 10));
}

int add_digits(int number)
{
    // recursive function to sum the digits in a given int
    if (number < 10)
        return number;
    else
        return (number % 10) + add_digits(number / 10);
}

