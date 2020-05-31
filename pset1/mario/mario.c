#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x;
    
    do
    {
        x = get_int("Height:");
    }
    while (x < 1 || x > 8);
    
    int n = x - 1;
    int p = x - n;
    
    //Creates the rows
    for (int i = 0; i < x; i++)
    {
        //prints the spaces
        for (int j = 0; j < n; j++)
        {
            printf(" ");
        }
        //prints the hashes
        for (int k = 0; k < p; k++)
        {
            printf("#");
        }
        //prints the center gap
        printf("  ");
        
        for (int l = 0; l < p; l++)
        {
            printf("#");
        }
    
    
        //moves to next row
        printf("\n");
        //increments the number of spaces and hashes per row
        n = n - 1;
        p++;
    }
    
}