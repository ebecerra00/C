#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Checks if argument exists
    if(argc != 2)
    {
        printf("Error, too many arguments, or none at all.\n");
        return 1;
    }

    //Length of argument 1
    int argv_length = strlen(argv[1]);

    //Checks if key has 26 letters and if it is an alphabetic character
    for(int key = 0; key < argv_length; key++)
    {
        //Checks for 26 letters
        if(argv_length != 26)
        {
            printf("Error, argument is not 26 letters\n");
            return 1;
        }
        //Checks is alphabetic character
        else if(isdigit(argv[1][key]))
        {
            printf("Error, alphabetic characters only\n");
            return 1;
        }
        //Checks if arguments displays the same letter
    for (int chk = key + 1; chk < argv_length; chk++)
    {
        if(argv[1][key] == argv[1][chk])
        {
            printf("Error, cannot duplicate values\n");
            return 1;
        }
    }
    }

    //Collecting user input
    string plaintext = get_string("plaintext:  ");

    //User output
    printf("ciphertext: ");

    //String length of plaintext
    int plaintext_length = strlen(plaintext);

    //Apply the cipher
    for (int c = 0; c < plaintext_length; c++)
    {
        if(isupper(plaintext[c]))
        {
            printf("%c", toupper(argv[1][plaintext[c]-65]));
        }
        else if(islower(plaintext[c]))
        {
            printf("%c", tolower(argv[1][plaintext[c]-97]));
        }
        else
        {
            printf("%c", plaintext[c]);
        }
    }
    printf("\n");
}