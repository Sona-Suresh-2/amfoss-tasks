#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n;
    int r = 1;
    
    printf("Enter a number: ");
    scanf("%d",&n);
    
    for(int i=n; i>=1;i--)
    {
        for(int j=1;j<=i-1;j++)
        {
            printf("");
        }
        for(int x=1;x<=r;x++)
        {
            printf("*");
        }
        printf("\n");
        r++;
    }
    return 0;
}