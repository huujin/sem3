#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool flag = true, only = true;
    int a; 
    a = getchar();
    int start = 0, end = 0, i = 0;
    while (a != '\n')
    {
        if (a != '-')
        {
            if (only) // если у нас идет обыный двойной промежуток
            {
                if (flag) //если мы не начали промежуток
                {
                    start = a;
                    flag = false; //обозначаем что начали строку
                    i++; //помогает считать двойной или тройной промежуток
                }
                else //если уже начали
                {
                    end = a;
                    flag = true; //обозначаем что закончили
                    i++;
                }
            }
            else //если у нас не двойной промежуток
            {
                start = end + 1; // делаем "второй" недостающий промежуток
                end = a;
                flag = true; // значит закончили
                only = true; // значит тройной промежуток
            }
        }
        else // если "-"
        {
            if (flag && (i != 0)) // если мы закончили и у нас уже не пустой промежуток 
                only = false; // промежуток тройной
        }
        if (flag && only) // если мы закончили и у нас двойной промежуток 
        {
            if (end > start)
            {
                for (int j = start; j <= end; j++)
                {
                    putchar(j);
                }
            }
            else
            {
                for (int j = start; j >= end; j--)
                {
                    putchar(j);
                }
            }
        }
        a = getchar();
    }
    //так как мы выводим все динамически и выведем при a-c-f при одном из проходов abc, то нам надо будет вывести недостающий остаток от тройного промежутка
    return 0;
}