#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STR_SIZE 100

int find_str(char* str1, char* str2)
{   
    int index = -1, length = strlen(str2), k = 0;
    // int mas[10] = {-1};
    for (int i = 0; i < strlen(str1) - length + 1; i++)
    {
        k = 0;
        if (str1[i] == str2[0])
        {
            for (int j = 0; j < length; j++)
            {
                if (str1[i+j] == str2[j])
                {
                    k++;
                }
            }
            if (k == length)
            {
                // mas[zxc] = i;
                index = i;
            }
        }
    }
    return index;
}

char* delete(char* string, int index, int length)
{
    if (index >= 0)
    {
        int j = 0;
        char* s = (char*) malloc(STR_SIZE * sizeof(char)); // создал новый пустой массив
        memset(s, 0, sizeof(s));
        for (int i = 0; i < strlen(string); i++)
        {
            if ((i < index) || (i >= (index + length)))
            {
                s[j] = string[i];
                j++;
            }
        }
        return (char*)s;
    }
    else
    {
        return string;
    }
    
    
}

int main(void)
{
    char* s1 = (char*) malloc(STR_SIZE * sizeof(char)); // инициализация первой строки
    scanf("%s", s1); // запись первой строки
    char* s2 = (char*) malloc(STR_SIZE * sizeof(char)); // инициализация второй строки
    scanf("%s", s2); // запись второй строки
    
    s1 = delete(s1, find_str(s1, s2), strlen(s2));

    for (int i = 0; i < strlen(s1); i++) // вывод строки
    {
        putchar(s1[i]);
    }
    return 0;
}
