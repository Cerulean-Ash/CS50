#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


char alphabetUpper[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char alphabetLower[26] = "abcdefghijklmnopqrstuvwxyz";


int main(int argc, string argv[])
{

    
    if (argc != 2)
    {
        printf("Key please.\n");
        return 1;
    }
    
    
    
    string key = argv[1];
    

    //string key = get_string("key: "); //hijktuvwxyZPqrabcdefglmnos
    int keyLength = strlen(key);
    
    //Validation:
    
    char validationKey[100];
    
    //strcpy(validationKey, key);
    // keylength validation:
    if (keyLength != 26)
    {
        printf("Key must contain 26 characters.\n"); 
        return 1;
    }
    
    // duplicate values validation
    for (int l = 0; l < keyLength; l++)
    {
        for (int m = 0; m < keyLength; m++)
        {
            if (key[l] == key[m])
            {
                for (int n = m + 1; n < keyLength; n++)
                {
                    if (key[l] == key[n])
                    {
                        printf("No duplicate values allowed.\n"); 
                        return 1;
                    }
                }
            }
        }
    }
    
    //validate alphabetic characters:
    int validationKeyCounter = 0;
    for (int o = 0; o < keyLength; o++) 
    {
        for (int p = 0; p < keyLength; p++)
        {
            if (key[o] == alphabetUpper[p])
            {
                validationKeyCounter++;
            } 
            if (key[o] == alphabetLower[p])
            {
                validationKeyCounter++;
            } 
        }
    }
    if (validationKeyCounter < keyLength)
    {
        printf("Only ketters allowed.\n");
        return 1;
    }
    
    
  
    
    //create upper and lowercase variants of key
    char upperKey[26] = "abcdefghijklmnopqrstuvwxyz";
    char lowerKey[26] = "abcdefghijklmnopqrstuvwxyz";
    int upperLength = strlen(upperKey);
    
    

    for (int i = 0; i < keyLength; i++) 
    {
        upperKey[i] = toupper(key[i]);
        lowerKey[i] = tolower(key[i]);
    }
    
    //get the message to be encrypted
    string message = get_string("plaintext: ");
    
    int messageLength = strlen(message);
    
    char cipherMessage[100];
    strcpy(cipherMessage, message);
   
    
    //Cipher Algorithm:
    for (int i = 0; i < messageLength; i++)
    {
         
        
        for (int j = 0; j < keyLength; j++)
        {
            if (message[i] == alphabetLower[j])
            {
           
                cipherMessage[i] = lowerKey[j];
            
            }  
        }
        
        for (int k = 0; k < keyLength; k++)
        {
            if (message[i] == alphabetUpper[k])
            {
            
                cipherMessage[i] = upperKey[k];
            }  
        }
    }
    
    
    
    printf("ciphertext: %s\n", cipherMessage);
    
    return 0;


}