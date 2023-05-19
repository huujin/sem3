#include <stdio.h>

void Vertical (int mas[128])
{
    for (int i = 0; i < 128; i++)
    {
        if (mas[i] != 0)
        {
            putchar(i);
            printf(": ");
            for (int j = 0; j < mas[i]; j++)
            {
                putchar('#');
            }
            putchar('\n');
        }        
    }
}

void Horizontal(int mas[128], int counter)
{
    int maximum = -1;
    for (int i = 0; i < 128; i++)
    {
        if (mas[i] > maximum)
        {
            maximum = mas[i];
        }
    }
    for (int i = maximum; i > 0; i--)
    {
        for (int j = 0; j < 128; j++)
        {
            if (mas[j]!=0)
            {
                if (mas[j] >= maximum)
                {
                    putchar('#');
                }
                else
                {
                    putchar(' ');
                }
                putchar(' ');
            }
        }
        maximum--;
        putchar('\n');
    }
    for (int i = 0; i < 128; i++)
    {
        if(mas[i]!=0)
        {
            putchar(i);
            putchar(' ');
        }
    }
    
}


int main(void)
{
    int mas[128] = {0};
    int a, counter=0;
    a = getchar();
    while (a != '\n')
    {
        mas[a]++;
        counter++;
        a = getchar();
    }
    Vertical(mas);
    Horizontal(mas, counter);
    return 0;
}