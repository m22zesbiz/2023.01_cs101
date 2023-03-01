#include <stdio.h>

int main()
{
    char a[] = "ABC123";
    int len = sizeof(a) / sizeof(char) - 1;
    int shift = 2;
    char temp[100];
    int j = 0;
    for (int i = shift; i < len; i++)
    {
        temp[j++] = a[i];
    }
    for (int i = 0; i < shift; i++)
    {
        temp[j++] = a[i];
    }
    for (int i = 0; i < len; i++)
    {
        printf("%c", temp[i]);
    }
}