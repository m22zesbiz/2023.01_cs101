#include <stdio.h>

int main()
{
    char a[] = "A3B2C4A9";
    int len = sizeof(a) / sizeof(char) - 1;
    for (int i = 0; i < len; i++)
    {
        if (a[i] - '0' < 10)
        {
            int count = a[i] - '0';
            for (int j = 1; j < count; j++)
            {
                printf("%c", a[i - 1]);
            }
        }
        else
        {
            printf("%c", a[i]);
        }
    }
}