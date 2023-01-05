#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Checks if there is any input at all
    if (argc != 2)
    {
        printf("Argument must not be blank.\n");
        return 1;
    }

    //Checks if input is a number and only a number
    for(int key = 0; key < strlen(argv[1]); key++)
    {
    if (isalpha(argv[1][key]))
    {
        printf("./caesar key\n");
        return 1;
    }
    }

    //Converts plaintext to integer
    int key = atoi(argv[1]) % 26;

    //Gets plaintext from the user
    string plaintext = get_string("Enter plaintext:  ");
    printf("ciphertext: ");

    //Applies the cipher
    for(int c = 0, length = strlen(plaintext); c < length; c++)
    {
        if(!isalpha(plaintext[c]))
        {
            printf("%c", plaintext[c]);
            continue;
        }
        int offset = isupper(plaintext[c]) ? 65 : 97;
        int a = plaintext[c] - offset;
        int ab = (a + key) % 26;

        printf("%c", ab + offset);
    }
    printf("\n");
}