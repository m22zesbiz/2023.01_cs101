#include <stdio.h>

int strLen(char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len - 1;
}

int pwrOfTen(int pwr) {
    int num = 1; 
    for (int i = 0; i < pwr; i++) {
        num *= 10;
    }
    return num; 
}

int getNumFromStr(char str[], int len)
{
    int num = 0;
    char temp[100];
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] - '0' >= 0 && str[i] - '0' < 10)
        {
            temp[j++] = str[i];
        }
    }
    for (int i = 0; i < strLen(temp); i++)
    {
        num += (temp[i] - '0') * pwrOfTen(strLen(temp) - 1 - i);
    }
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '-')
        {
            num *= -1;
        }
    }
    printf("%d\n", num);
}

int main()
{
    char a[] = "-99acbc";
    char b[] = "99acbc";
    char c[] = "ac-99bc";
    getNumFromStr(a, strLen(a));
    getNumFromStr(b, strLen(b));
    getNumFromStr(c, strLen(c));
}