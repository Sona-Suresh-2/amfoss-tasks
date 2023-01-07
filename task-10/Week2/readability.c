#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>


int main(void)
{
    string text = get_string("Enter the text here: ");
    printf("The text is: %s\n", text);
    
    
    int letters = 0;
    for(int i=0; i<strlen(text); i++)
    {
        if((text[i]>='A' && text[i]<= 'Z') || (text[i]>= 'a' && text[i]<= 'z') )
        letters++;
    }
    printf("%i letters\n",letters);
    
    int words = 1;
    for(int i=0; i<strlen(text); i++)
    {
        if (text[i]==' ')
        words++;
    }
    printf("%i words\n",words);
    
    int sentences = 0;
    for(int i=0; i<strlen(text); i++)
    {
        if(text[i]=='.'||text[i]==','||text[i]=='!'||text[i]=='?')
        sentences++;
    }
    printf("%i sentences\n",sentences);
    
    float calculation = (0.0588*letters/words*100)-(0.296*sentences/words*100)-15.8;
    int index = round(calculation);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
      printf("Grade 16+\n");
      return 0;
    }
    else
    {
        printf("Grade %i\n",index);
    }
}
