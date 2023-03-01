#include <stdio.h>

int main()
{
    char a[] = "Hello";
    int len = sizeof(a) / sizeof(char) - 1;

    for (int i = 0; i < len / 2; i++)
    {
        char temp = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = temp;
    }

    if (a[0] > 90)
    {
        a[0] = a[0] - 32;
    }

    if (a[len - 1] < 91)
    {
        a[len - 1] = a[len - 1] + 32;
    }

    printf("%s\n", a);
}