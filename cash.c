/* 
Harvard CS50-Project-2
Synopsis: --
 
*/
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <cs50.h>




// prompts user for non-negative value, and converts floats to int because of floating point imprecision.
float ask(void); 
// algorithm that determines the most efficient method to reach 0.
void change(int currency); 

int main()
{
    // variable declaration for clarity.
    int currency_rf = ask(); 
    change(currency_rf);


}


float ask(void)
{
    while (true)
    {
        float currency = get_float("change is owed: ");
        if (currency > 0)
        {
            // converts & rounds float to int to avoid floating-point imprecision.
            int currency_rf = round(currency  * 100); 
            return currency_rf;
        }
    }

}

void change(int currency)
{
    // array declaration of length 4. 0.25 - 25 ... 0.01 - 1
    int change[4] = {25, 10, 5, 1}; 


    // length of array. nonarbitrary 
    size_t change_length = sizeof(change[4]); 
    
    int index;
    int count; // set count.
    count = 1;
    // NOTE: exclud step condition. 
    for (index = 0; index < change_length;) 
    {
        // Ex: 0th index | 145 - 25 = 120. 120 - 25 = 95 ...
        currency = currency - change[index]; 

        // printf("Count: %i Currency: %i Change: %i \n", count, currency, change[index]);

        // after 'step', if currency does not equal to zero, then execute body of if statement.
        if (currency != 0) 
        {
            // IF currency is less than zero => curreny needs to back-track. 
            if (currency < 0) 
            {
                // back-track and try 10. if next index (10) yields a non-positive value, then try the next index (5)
                currency = currency + change[index]; 
                index++; 
            }
            else
            {
                // as long as currency is a non-negative value, add 1 to count.
                count++; 
            }
        }
        else
        {
            printf("%i", count);
            printf("\n");
            return; 
        }

    }

}