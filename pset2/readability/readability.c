#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    //get the extract of text to test/grade
    string text = get_string("Text:\n");
   
    // determine the lenth of the text
    int textLength = strlen(text);
   
   
    float word = 1;
    float letter = 0;
    float sentence = 0;
    for (int i = 0; i < textLength; i++) 
    {
        //get number of letters
        if (isalpha(text[i]))
        {
            letter++;
        }
        //get number of words
        if (isspace(text[i]))
        {
            word++;
        }
        //get number of sentences
        if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentence++;
        }
    }
    
   
    float index;
    float l;
    float s;
   
    l = letter / word * 100;
    s = sentence / word * 100;
   
    index = round(0.0588 * l - 0.296 * s - 15.8);
   
   
   
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16)
    {
        printf("Grade %.0f\n", index);
    }
    else 
    {
        printf("Grade 16+\n");
    }
   
   
   
  
    
    
    //tests
    /* printf("%f\n", letter);
       printf("%f\n", word);
       printf("%f\n", sentence);
       printf("%f\n", l);
       printf("%f\n", s);
       printf("%f\n", index);
     */
    
    
}