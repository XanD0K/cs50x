#include "helpers.h"
#include <math.h>

void swap_pixel(RGBTRIPLE *pixel_left, RGBTRIPLE *pixel_right);
void blur_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width], RGBTRIPLE temporary[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round(((float) (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)) / 3);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int cap = 255;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > cap)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > cap)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > cap)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
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
            int right = width - 1 - j;
            swap_pixel(&image[i][j], &image[i][right]);
        }
    }
    return;
}

// Created to do the pixel swap and keep the original code more organized
void swap_pixel(RGBTRIPLE *pixel_left, RGBTRIPLE *pixel_right)
{
    RGBTRIPLE pixel_temp;

    pixel_temp = *pixel_left;
    *pixel_left = *pixel_right;
    *pixel_right = pixel_temp;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Use the temporary variable as a reference, so that when doing the 3x3 average you don't use already blurred values in new pixels
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
    int sum_red = 0;
    int sum_green = 0;
    int sum_blue = 0;
    int counter = 0;

    for (int k = i - 1; k <= i + 1; k++)
    {
        for (int l = j - 1; l <= j + 1; l++)
        {
            if (k < 0 || k >= height || l < 0 || l >= width) // CS50 Duck Debugger suggestion
            {
                continue;
            }

            sum_red += temporary[k][l].rgbtRed;
            sum_green += temporary[k][l].rgbtGreen;
            sum_blue += temporary[k][l].rgbtBlue;
            counter++;
        }
    }

    // I need to use uint8_t to declare the blurred average. the original rgbtRed/Green/Blue is a uint8_t variable type
    uint8_t average_red = round((float) sum_red / counter);
    uint8_t average_green = round((float) sum_green / counter);
    uint8_t average_blue = round((float) sum_blue / counter);

    image[i][j].rgbtRed = average_red;
    image[i][j].rgbtGreen = average_green;
    image[i][j].rgbtBlue = average_blue;

    return;
}
