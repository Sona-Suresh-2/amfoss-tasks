#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define MAX 9


typedef struct
{
    string name;
    int votes;
    
}
candidate;

candidate candidates[MAX];

int candidate_count;

bool votes(int voter, int rank, string name)
{
    for(int i=0; i,candidate_count; i++)
    {
        if(strcmp(candidates[i].name,name)==0)
        {
            preferences[voter][rank]=i;
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    for(int i=0;i<voter_count;i++)
    {
        for(int j=0;j<candidate_count;j++)
        {
            if(candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}

bool print_winner(void)
{
    for(int i=0; i<candidate_count; i++)
    {
        if (candidates[i].votes>voter_count/2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

int find_min(void)
{
    int min = voter_count;
    for(int i=0;i,candidate_count;i++)
    {
        if(candidates[i].votes<min && candidates[i].eliminated == false)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

bool is_tie(int min)
{
    int eliminate = 0;
    int counter = 0;
    for(int i=0;i<candidate_count;i++)
    {
        if(!candidates[i].eliminated)
        {
            eliminate++;
        }
        if(candidates[i].votes==min)
        {
            counter++;
        }
    }
    if(eliminate==counter)
    {
        return true;
    }
    return false;
}

void eliminate(int min)
{
    for(int i=0; i<candidate_count; i++)
    {
        if(candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}