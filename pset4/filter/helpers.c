#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbGrayScale;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            rgbGrayScale = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.00);
            image[i][j].rgbtBlue = rgbGrayScale;
            image[i][j].rgbtGreen = rgbGrayScale;
            image[i][j].rgbtRed = rgbGrayScale;
        }
    }
    return;
}
int colorlimit(int color)
{
    if (color > 255)
    {
        color = 255;
    }
    return color;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //using sepia color algorithm
            sepiaRed = colorlimit(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            sepiaGreen = colorlimit(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            sepiaBlue = colorlimit(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) //width is divided by 2 else the new row will be same as original row
        {
            temp[0] = image[i][j].rgbtRed;
            temp[1] = image[i][j].rgbtGreen;
            temp[2] = image[i][j].rgbtBlue;
            //swapping the pixels in a row from left side to right side
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = temp[0];
            image[i][width - j - 1].rgbtGreen = temp[1];
            image[i][width - j - 1].rgbtBlue = temp[2];

        }
    }
    return;
}
int blurImage(int i, int j, int height, int width, RGBTRIPLE image[height][width], int colornum)
{
    float counter = 0;
    int sum = 0;
    //to get sum of colors in neighbour pixels of current pixels
    for (int m = i - 1; m < (i + 2); m++) //taking two rows before and after current row
    {
        for (int n = j - 1; n < (j + 2); n ++) //taking two pixels before and after current pixel
        {
            if (m < 0 || m >= height || n < 0 || n >= width)
            {
                continue;
            }
            if (colornum == 0)
            {
                sum += image[m][n].rgbtRed;
            }
            else if (colornum == 1)
            {
                sum += image[m][n].rgbtGreen;
            }
            else
            {
                sum += image[m][n].rgbtBlue;
            }
            counter++;
        }
    }
    return round(sum / counter);
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];

        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = blurImage(i, j, height, width, temp, 0);
            image[i][j].rgbtGreen = blurImage(i, j, height, width, temp, 1);
            image[i][j].rgbtBlue = blurImage(i, j, height, width, temp, 2);
        }
    }
    return;
}
