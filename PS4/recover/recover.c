#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Open File
    FILE *input_file = fopen(argv[1], "r");

    //Check if it is a file
    if(!input_file)
    {
        printf("Error: Could not open file.\n");
        return 1;
    }

    //Check if argument is there
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    //Varible to store 512 chunks array
    unsigned char buffer[512];

    //Count images
    int count_image = 0;

    //Use to output data goten from input
    FILE *output_file = NULL;

    char *filename = malloc(8 * sizeof(char));

    //Repeat until end of card, read 512 bytes into a buffer
    while(fread(buffer, sizeof(char), 512, input_file))
    {
        //Check first three bypes
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Write jpeg into file name
            sprintf(filename, "%03i.jpg", count_image);
            //Open file for writing
            output_file = fopen(filename, "w");
            //Count images
            count_image++;
        }
        //Check if output has been used
        if(output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}