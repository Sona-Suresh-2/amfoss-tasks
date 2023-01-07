#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float cents = get_float("Change Owed: ");
    float cents = round(cents*100)
    printf("%f\n",cents);
    
}