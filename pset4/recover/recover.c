#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>

typedef uint8_t BYTE;

#define FALSE 0
#define TRUE !(FALSE)

int main(int argc, char *argv[])
{
    
    //open card
    FILE *fCard = fopen(argv[1], "r");
    
    if (argc != 2)
    {
        printf("incorrect number of command line arguments.\n");
        return 1;
    }
    
    //check card validity
    if (fCard == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }
    
    // create buffer
    BYTE buffer[512];
    
    FILE *pic = NULL;
    
    
    // create counter and verifier
    int fileNumber = 0;
    int picFound = FALSE;
    
   
    while (fread(buffer, sizeof(buffer), 1, fCard) == TRUE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //first pic found
            if (picFound == FALSE)
            {
                picFound = TRUE;
                
                //create new file
                char filename[8];
                sprintf(filename, "%03i.jpg", fileNumber);
                pic = fopen(filename, "a");
            }
            
            //new pic found
            else if (picFound == TRUE)
            {
                fclose(pic);
                
                fileNumber++;
                //create new file
                char filename[8];
                sprintf(filename, "%03i.jpg", fileNumber);
                pic = fopen(filename, "a");
            }
            
            
            
        }
        
        if (picFound == TRUE)
        {
            fwrite(buffer, sizeof(buffer), 1, pic);
        }
       
    }
    
    
    
    

    fclose(fCard);

    return 0;

}
