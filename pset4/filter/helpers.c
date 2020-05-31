#include "helpers.h"
#include <math.h>
#include <stdlib.h>



// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float colorSum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            float avgColor = round(colorSum / 3);
            image[i][j].rgbtBlue = (avgColor);
            image[i][j].rgbtGreen = (avgColor);
            image[i][j].rgbtRed = (avgColor);
            
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Create copy
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
            
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temp image:
    RGBTRIPLE tempo[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempo[i][j] = image[i][j];
        }
    }
    
    // Blur original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float colorSumRed = 0;
            float colorSumBlue = 0;
            float colorSumGreen = 0;

            //Cases
            int o;
            int p;
            int q;
            int r;
            float num;
            
            //case 1
            if (i == 0 && j == 0)
            {
                o = 0;
                p = 2;
                q = 0;
                r = 2;
                num = 4;
            } 
            //case 3
            else if (i == 0 && j == width - 1)
            {
                o = 0;
                p = 2;
                q = -1;
                r = 1;
                num = 4;
            }
            //case 5
            else if (i == height - 1 && j == width - 1)
            {
                o = -1;
                p = 1;
                q = -1;
                r = 1;
                num = 4;
            }
            //case 7
            else if (i == height - 1 && j == 0)
            {
                o = -1;
                p = 1;
                q = 0;
                r = 2;
                num = 4;
            }
            //case 2
            else if (i == 0)
            {
                o = 0;
                p = 2;
                q = -1;
                r = 2;
                num = 6;
            }
            //case 4
            else if (j == width - 1)
            {
                o = -1;
                p = 2;
                q = -1;
                r = 1;
                num = 6;
            }
            //case 6
            else if (i == height - 1)
            {
                o = -1;
                p = 1;
                q = -1;
                r = 2;
                num = 6;
            }
            //case 8
            else if (j == 0)
            {
                o = -1;
                p = 2;
                q = 0;
                r = 2;
                num = 6;
            }
            //main case (case 9)
            else
            {
                o = -1;
                p = 2;
                q = -1;
                r = 2;
                num = 9;
            }
            
            for (int k = o; k < p; k++)
            {
                for (int l = q; l < r; l++)
                {
                    colorSumRed += tempo[i + k][j + l].rgbtRed;
                    colorSumBlue += tempo[i + k][j + l].rgbtBlue;
                    colorSumGreen += tempo[i + k][j + l].rgbtGreen;
                }
            }
            //Final application of Blur
            float avgColorRed = round(colorSumRed / num);
            float avgColorBlue = round(colorSumBlue / num);
            float avgColorGreen = round(colorSumGreen / num);
            image[i][j].rgbtBlue = (avgColorBlue);
            image[i][j].rgbtGreen = (avgColorGreen);
            image[i][j].rgbtRed = (avgColorRed); 
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //create constants
    float redGx;
    float greenGx;
    float blueGx;
    
    float redGy;
    float greenGy;
    float blueGy;
    
    float colorRed;
    float colorGreen;
    float colorBlue;
    
    RGBTRIPLE temp[height][width];
 
    //Create copy of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
 
    //Loop through pixels
    for (int i = 0; i < height; i++)
    {
        
        for (int j = 0; j < width; j++)
        {
            redGx = 0.0;
            greenGx = 0.0;
            blueGx = 0.0;
 
            redGy = 0.0;
            greenGy = 0.0;
            blueGy = 0.0;
 
            colorRed = 0;
            colorGreen = 0;
            colorBlue = 0;
 
            //Apply edge checking
            for (int k = -1; k < 2; k++)
            {
                //Check for out-of-bounds at top and bottom
                if (i + k < 0 || i + k > height - 1)
                {
                    continue;
                }
 
                for (int l = -1; l <= 1; l++)
                {
                    //Check for out-of-bounds at left and right
                    if (j + l < 0 || j + l > width - 1)
                    {
                        continue;
                    }
 
                    if (k == -1)
                    {
                        // Top left
                        if (l == -1)
                        {
                            redGx += (-1 * temp[i + k][j + l].rgbtRed);
                            greenGx += (-1 * temp[i + k][j + l].rgbtGreen);
                            blueGx += (-1 * temp[i + k][j + l].rgbtBlue);
 
                            redGy += (-1 * temp[i + k][j + l].rgbtRed);
                            greenGy += (-1 * temp[i + k][j + l].rgbtGreen);
                            blueGy += (-1 * temp[i + k][j + l].rgbtBlue);
                        }
                        // Top center
                        else if (l == 0)
                        {
                            redGy += (-2 * temp[i + k][j + l].rgbtRed);
                            greenGy += (-2 * temp[i + k][j + l].rgbtGreen);
                            blueGy += (-2 * temp[i + k][j + l].rgbtBlue);
                        }
                        // Top right
                        else
                        {
                            redGx += temp[i + k][j + l].rgbtRed;
                            greenGx += temp[i + k][j + l].rgbtGreen;
                            blueGx += temp[i + k][j + l].rgbtBlue;
 
                            redGy += (-1 * temp[i + k][j + l].rgbtRed);
                            greenGy += (-1 * temp[i + k][j + l].rgbtGreen);
                            blueGy += (-1 * temp[i + k][j + l].rgbtBlue);
                        }
                    }
                    else if (k == 0)
                    {
                        // Center left
                        if (l == -1)
                        {
                            redGx += (-2 * temp[i + k][j + l].rgbtRed);
                            greenGx += (-2 * temp[i + k][j + l].rgbtGreen);
                            blueGx += (-2 * temp[i + k][j + l].rgbtBlue);
                        }
                        // Center
                        else if (l == 0)
                        {
                            
                        }
                        // Center right
                        else
                        {
                            redGx += (2 * temp[i + k][j + l].rgbtRed);
                            greenGx += (2 * temp[i + k][j + l].rgbtGreen);
                            blueGx += (2 * temp[i + k][j + l].rgbtBlue);
                        }
                    }
                    else
                    {
                        // Bottom left
                        if (l == -1)
                        {
                            redGx += (-1 * temp[i + k][j + l].rgbtRed);
                            greenGx += (-1 * temp[i + k][j + l].rgbtGreen);
                            blueGx += (-1 * temp[i + k][j + l].rgbtBlue);
 
                            redGy += temp[i + k][j + l].rgbtRed;
                            greenGy += temp[i + k][j + l].rgbtGreen;
                            blueGy += temp[i + k][j + l].rgbtBlue;
                        }
                        // Bottom center
                        else if (l == 0)
                        {
                            redGy += (2 * temp[i + k][j + l].rgbtRed);
                            greenGy += (2 * temp[i + k][j + l].rgbtGreen);
                            blueGy += (2 * temp[i + k][j + l].rgbtBlue);
                        }
                        // Bottom right
                        else
                        {
                            redGx += temp[i + k][j + l].rgbtRed;
                            greenGx += temp[i + k][j + l].rgbtGreen;
                            blueGx += temp[i + k][j + l].rgbtBlue;
 
                            redGy += temp[i + k][j + l].rgbtRed;
                            greenGy += temp[i + k][j + l].rgbtGreen;
                            blueGy += temp[i + k][j + l].rgbtBlue;
                        }
                    }
                }
            }
 
          
            //Combine Gx and Gy
            colorRed = round(sqrt(pow(redGx, 2) + pow(redGy, 2)));
            colorGreen = round(sqrt(pow(greenGx, 2) + pow(greenGy, 2)));
            colorBlue = round(sqrt(pow(blueGx, 2) + pow(blueGy, 2)));
 
            if (colorRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = colorRed;
            }
 
            if (colorGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = colorGreen;
            }
 
            if (colorBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = colorBlue;
            }
        }
    }
    
    return;
}
