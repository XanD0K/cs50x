#include "helpers.h"
#include <math.h>

void swap_pixel(RGBTRIPLE *before, RGBTRIPLE *after);
void blur_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width],
                RGBTRIPLE temporary[height][width]);
void edges_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width],
                 RGBTRIPLE temporary[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round(((float) (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)) / 3);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap_pixel(&image[i][j], &image[i][width - 1 - j]);
        }
    }
    return;
}

void swap_pixel(RGBTRIPLE *before, RGBTRIPLE *after)
{
    RGBTRIPLE temporary = *before;
    *before = *after;
    *after = temporary;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temporary[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temporary[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blur_pixel(i, j, height, width, image, temporary);
        }
    }

    return;
}

void blur_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE temporary[height][width])
{
    int sumRed = 0, sumGreen = 0, sumBlue = 0;
    int count = 0;

    for (int k = i - 1; k <= i + 1; k++)
    {
        for (int l = j - 1; l <= j + 1; l++)
        {
            if (k < 0 || k >= height || l < 0 || l >= width)
            {
                continue;
            }

            sumRed += temporary[k][l].rgbtRed;
            sumGreen += temporary[k][l].rgbtGreen;
            sumBlue += temporary[k][l].rgbtBlue;
            count++;
        }
    }

    uint8_t averageRed = round((float) sumRed / count);
    uint8_t averageGreen = round((float) sumGreen / count);
    uint8_t averageBlue = round((float) sumBlue / count);

    image[i][j].rgbtRed = averageRed;
    image[i][j].rgbtGreen = averageGreen;
    image[i][j].rgbtBlue = averageBlue;
}

// Detect edges
// Almost the same as the blur function. The exceptions will come in the edges_pixel function
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temporary[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temporary[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            edges_pixel(i, j, height, width, image, temporary);
        }
    }

    return;
}

void edges_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE temporary[height][width])
{
    int Gx[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int Gy[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    double GxsumRed = 0, GxsumGreen = 0, GxsumBlue = 0;
    double GysumRed = 0, GysumGreen = 0, GysumBlue = 0;
    int counter_array = 0;
    int cap = 255;

    for (int k = i - 1; k <= i + 1; k++)
    {
        for (int l = j - 1; l <= j + 1; l++)
        {
            if (k < 0 || k >= height || l < 0 || l >= width)
            {
                // I can't just "skip" the out of bound pixel. I also need to increase the counter
                counter_array++;
                continue;
            }

            GxsumRed += temporary[k][l].rgbtRed * Gx[counter_array];
            GxsumGreen += temporary[k][l].rgbtGreen * Gx[counter_array];
            GxsumBlue += temporary[k][l].rgbtBlue * Gx[counter_array];

            GysumRed += temporary[k][l].rgbtRed * Gy[counter_array];
            GysumGreen += temporary[k][l].rgbtGreen * Gy[counter_array];
            GysumBlue += temporary[k][l].rgbtBlue * Gy[counter_array];

            counter_array++;
        }
    }

    // sqrt function outputs a double
    double tempRed = round(sqrt((GxsumRed * GxsumRed) + (GysumRed * GysumRed)));
    double tempGreen = round(sqrt((GxsumGreen * GxsumGreen) + (GysumGreen * GysumGreen)));
    double tempBlue = round(sqrt((GxsumBlue * GxsumBlue) + (GysumBlue * GysumBlue)));

    if (tempRed > cap)
    {
        tempRed = cap;
    }
    if (tempGreen > cap)
    {
        tempGreen = cap;
    }
    if (tempBlue > cap)
    {
        tempBlue = cap;
    }

    // Converting double to uint8_t so that it can be assigned to rgbt
    uint8_t finalRed = (uint8_t) tempRed;
    uint8_t finalGreen = (uint8_t) tempGreen;
    uint8_t finalBlue = (uint8_t) tempBlue;

    image[i][j].rgbtRed = finalRed;
    image[i][j].rgbtGreen = finalGreen;
    image[i][j].rgbtBlue = finalBlue;
}
