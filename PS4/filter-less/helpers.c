#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg_bit;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            avg_bit = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00);

            image[i][j].rgbtRed = avg_bit;
            image[i][j].rgbtGreen = avg_bit;
            image[i][j].rgbtBlue = avg_bit;
        }
    }
    return;
}

    int limit(int RGB)
    {
        if (RGB > 255)
        {
            RGB = 255;
        }
    return RGB;
    }

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float red_sepia;
    float green_sepia;
    float blue_sepia;
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            red_sepia = limit(round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue));
            green_sepia = limit(round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue));
            blue_sepia = limit(round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = red_sepia;
            image[i][j].rgbtGreen = green_sepia;
            image[i][j].rgbtBlue = blue_sepia;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmp[3];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width / 2; j++)
        {
            tmp[0] = image[i][j].rgbtBlue;
            tmp[1] = image[i][j].rgbtGreen;
            tmp[2] = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = tmp[0];
            image[i][width - j - 1].rgbtGreen = tmp[1];
            image[i][width - j - 1].rgbtRed = tmp[2];
        }
    }
    return;
}

int getBlur(int i, int j, int height, int width, RGBTRIPLE image[height][width], int color_position)
{
    float counter = 0;
    int sum = 0;

    for(int k = i - 1; k < (i + 2); k++)
    {
        for(int l = j - 1; l < (j + 2); l++)
        {
            if(k < 0 || l < 0 || k >=height || 1 >= width)
            {
                continue;
            }
            if(color_position == 0)
            {
                sum += image[k][l].rgbtRed;
            }
            else if(color_position == 1)
            {
                sum += image[k][l].rgbtGreen;
            }
            else
            {
                sum += image[k][l].rgbtBlue;
            }
            counter++;
        }
    }
    return round(sum /counter);
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = getBlur(i, j, height, width, copy, 0);
            image[i][j].rgbtGreen = getBlur(i, j, height, width, copy, 1);
            image[i][j].rgbtBlue = getBlur(i, j, height, width, copy, 2);
        }
    }
    return;
}
