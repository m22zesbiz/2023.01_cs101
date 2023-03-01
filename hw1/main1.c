#include <stdio.h>

int main()
{
    char a[] = "AABBBCCCCdd";
    int len = sizeof(a) / sizeof(char) - 1;
    int count = 1;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == a[i + 1])
        {
            count++;
        }
        else
        {
            printf("%c%d", a[i], count);
            count = 1;
        }
    }
}