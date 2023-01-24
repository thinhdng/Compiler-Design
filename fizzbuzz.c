/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int i;
    for(i = 1; i <=100; i++)
    {
        if(i % 3 == 0 && i % 5 != 0)
            printf("fizz\n");
        if(i % 5 == 0 && i % 3 != 0)
            printf("buzz\n");
        if(i % 3 == 0 && i % 5 == 0)
            printf("fizzbuzz\n");
        if(i % 3 != 0 && i % 5 != 0)
            printf("%i\n", i);
    }
}
