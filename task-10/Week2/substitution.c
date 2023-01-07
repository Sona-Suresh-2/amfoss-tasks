#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    for(int i=0; i<strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: .substitution key\n");
            return 1;
        }
    }
    if(strlen(key)!=26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for(int i=0;i<strlen(key);i++)
    {
        for(int j=i+1;j<strlen(key);j++)
        {
            if(toupper(key[i])==toupper(key[j]))
            {
                printf("Usage: .substitution key\n");
                return 1;
            }
        }
    }
    string plaintext = get_string("Plaintext: ");
    for(int i=0;i<strlen(plaintext);i++)
    {
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i]-65;
            printf("%c", key[letter]);
        }
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i]-97;
            printf("%c",key[letter]+32);
        }
        else 
        {
            printf("%c",plaintext[i]);
        }
    }
    printf("\n");
}

