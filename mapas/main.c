#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

void start_matrix(int m[26][26])
{
    int i,j=0;
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            m[i][j]=0;
        }
    }
}

void print_matrix(int m[26][26])
{
    int i,j;
    for(i=0;i<26;i++)
    {
        printf("\n");
        for(j=0;j<26;j++)
        {
          printf(" %d ",m[i][j]);
        }
    }
}

void set_border(int m[26][26], int a, int b)
{
    m[a][b] = 1;
    m[b][a] = 1;
}

int color_test(int m[26][26], int country, int color)
{
    int i;
    for (i=0;i<26;i++)
    {
        if (m[country][i] == 1)
        {
            if (m[i][i] == color) return(0);
        }
    }
    return(1);
}

void read(int m[26][26])
{
    FILE* MyFile;
    int c;
    int i = 0;
    int j = 0;
    MyFile = fopen("C:/gargsal.txt","r");
    c = fgetc(MyFile);
    while (c!=EOF)
    {
        if (i == j && c != ' ')
        {
            m[i][j] = c - 48;
            i++;
        }
        else if (c==49)
        {
            set_border(m, i, j);
            i++;
        }
        else if (c==48)
        {
            i++;
        }
        else if (c=='\n')
        {
            j++;
            i=0;
        }
        c = fgetc(MyFile);
    }
}

int color(int m[26][26], int country);

int color(int m[26][26], int country)
{
    if (country >= 26) return(1);
    int c;
    for (c=1;c<=4;c++)
    {
        if (color_test(m,country,c))
        {
            m[country][country] = c;
            color(m, country+1);
        }
    }
    return(0);
}

int main()
{
    int matrix[26][26];
    start_matrix(matrix);
    read(matrix);
    color(matrix, 0);
    print_matrix(matrix);
    return(0);
}
