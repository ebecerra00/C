#include <cs50.h> \\Extention library for string
#include <stdio.h> \\Standards extention library

int main(void)
{
    string name = get_string("What's your name?\n");
    printf("Hello, %s\n", name);
}