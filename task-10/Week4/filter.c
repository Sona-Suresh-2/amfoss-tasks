#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height;i++)
    {
        for(int j=0; j<width; j++)
        {
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;
            
            int average = round((Red + Green + Blue)/3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen=image[i][j].rgbtBlue = average;
        }
    }
    return;
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0; j<width;j++)
        {
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;
            
            int sepiaRed = round(0.393*originalRed+0.769*originalGreen+0.189*originalBlue);
            int sepiaGreen = round(0.349*originalRed + 0.686*originalGreen+0.168*originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            
            
            if(sepiaRed >255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen>255)
            {
                sepiaGreen = 255;
            }
            if(sepiaBlue>255)
            {
                sepiaBlue = 255;;
            }
            
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

void reflect(int height,int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width/2;j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j]=image[i][width-(j+1)];
            image[i][width-(j+1)]=temp;
        }
    }
    return;
}
void blur(int height, int width, RGBTRIPLE image[height][width]);
{
    RGBTRIPLE temp[height][width];
    for(int i=0; i<height; i++)
    {
        for(int j=0;j<width;j++)
        {
            temp[i][j]=image[i][j];
        }
    }
    for(int i=o;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;
            
            for(int x= -1; x<2; x++)
            {
                for(int y=-1; y<2; y++)
                {
                    int currentX = i+x;
                    int currenty = j+y;
                    
                    if(currentx <0 || currentx> (height-1)||currenty<0||currenty>(width-1))
                    {
                        continue;
                    }
                    
                    totalRed += image[currentx][currenty].rgbtRed;
                    totalGreen += image[currentx][currenty].rgbtGreen;
                    totalBlue += image[currentx][currenty].rgbtBlue;
                    
                    counter++;
                }
                
                temp[i][j].rgbtRed = round(totalRed/counter);
                temp[i][j].rgbtGreen = round(totalGreen/counter);
                temp[i][j].rgbtBlue = round(totalBlue/counter);
            }
        }
    }
    for(int i=0; i< height; i++)
    {
        for(int j=0; j<width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return
}
