#include <stdio.h>

int powerOfTwo(int num)
{
    int result = 1;
    for (int i = 0; i < num; i++)
    {
        result *= 2;
    }
    return result;
}

int convert(char str[])
{
    int firstDigit = 0;
    int secondDigit = 0;
    for (int i = 0; i < 8; i++)
    {
        if (i < 4)
        {
            firstDigit += (str[i] - '0') * powerOfTwo(7 - 4 - i);
        }
        else
        {
            secondDigit += (str[i] - '0') * powerOfTwo(7 - i);
        }
    }
    if (firstDigit < 10)
    {
        printf("%d", firstDigit);
    }
    else
    {
        switch (firstDigit)
        {
        case 10:
            printf("%c", 'A');
            break;
        case 11:
            printf("%c", 'B');
            break;
        case 12:
            printf("%c", 'C');
            break;
        case 13:
            printf("%c", 'D');
            break;
        case 14:
            printf("%c", 'E');
            break;
        case 15:
            printf("%c", 'F');
            break;
        }
    }
    if (secondDigit < 10)
    {
        printf("%d\n", secondDigit);
    }
    else
    {
        switch (secondDigit)
        {
        case 10:
            printf("%c\n", 'A');
            break;
        case 11:
            printf("%c\n", 'B');
            break;
        case 12:
            printf("%c\n", 'C');
            break;
        case 13:
            printf("%c\n", 'D');
            break;
        case 14:
            printf("%c\n", 'E');
            break;
        case 15:
            printf("%c\n", 'F');
            break;
        }
    }
}

int main()
{
    char a[] = "10001111";
    char b[] = "10011110";
    convert(a);
    convert(b);
}