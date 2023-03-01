#include <stdio.h>

int main()
{
    char a[] = "81c8g8u168";
    int aLen = sizeof(a) / sizeof(char) - 1;
    for (int i = 0; i < aLen; i++)
    {
        switch (a[i] - '0')
        {
        case 1:
            printf("%s ", "I");
            break;
        case 2:
            printf("%s ", "II");
            break;
        case 3:
            printf("%s ", "III");
            break;
        case 4:
            printf("%s ", "IV");
            break;
        case 5:
            printf("%s ", "V");
            break;
        case 6:
            printf("%s ", "VI");
            break;
        case 7:
            printf("%s ", "VII");
            break;
        case 8:
            printf("%s ", "VIII");
            break;
        case 9:
            printf("%s ", "IX");
            break;
        default:
            printf("%c ", a[i]);
        }
    }
}