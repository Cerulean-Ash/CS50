#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    long creditNo;
    do
    {
        creditNo = get_long("Input Credit Card Number:\n");
    } 
    while (creditNo < 1);  //ensures its a number
    
    
    long x = 10;
    int sum = 0;
    
    
    for (long i = 1; i <= creditNo; i = i * 10)
    {
        //prints out the inverse
        long digit = creditNo % x;
        long y = x / 10;
        long trueDigit = digit / y;
        //printf("%ld\n", trueDigit);
        
        //double up the digits and adds digits when number is double figure
        
        int z = round(log(x) / log(10)); //determines the exponential
        
        //printf("x is: %ld\n", x);
       
        //printf("z is: %d\n", z);
        int doubledDigits = 0;
        if (z % 2 == 0)
        {
            doubledDigits = trueDigit * 2;
            if (trueDigit >= 6)
            {
                doubledDigits = doubledDigits % 10 + 1;
            } 
            else if (trueDigit == 5)
            {
                doubledDigits = 1;
            }
        } 
        else 
        {
            doubledDigits = trueDigit;
        }
        //printf("dd is: %d\n", doubledDigits);
        
        sum = sum + doubledDigits;
        
        //printf("sum is: %d\n", sum);
        x *= 10;
    }
    
    int validator = sum % 10;
    int identifier = creditNo * 1000 / x;
    int identifierVisa = creditNo * 100 / x;
    
    //printf("identifier is: %d\n", identifier);
    
    if ((identifier == 34 || identifier == 37) && validator == 0 && creditNo > 340000000000000)
    {
        printf("AMEX\n");
    } 
    else if ((identifier == 51 || identifier == 52 || identifier == 53 || identifier == 54 || identifier == 55) && validator == 0
             && creditNo > 5100000000000000) 
    {
        printf("MASTERCARD\n");
    } 
    else if (identifierVisa == 4 && validator == 0 && creditNo > 4000000000000) 
    {
        printf("VISA\n");
    } 
    else 
    {
        printf("INVALID\n");
    }
    
}