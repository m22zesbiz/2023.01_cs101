#include <stdio.h>

int main()
{
    char a[] = "-9 8 7 6 5 -4 3 -2 1";
    int i = 4;
    int aLen = sizeof(a) / sizeof(char) - 1;
    int arr[aLen];
    int j = 0;

    for (int k = 0; k < aLen; k++)
    {
        if (a[k] != ' ' && a[k] != '-')
        {
            if (a[k - 1] == '-')
            {
                arr[j++] = (a[k] - '0') * -1;
            }
            else
            {
                arr[j++] = a[k] - '0';
            }
        }
    }

    for (int k = 0; k < j - 1; k++)
    {
        for (int l = k + 1; l < j; l++)
        {
            if (arr[k] > arr[l])
            {
                int temp = arr[k];
                arr[k] = arr[l];
                arr[l] = temp;
            }
        }
    }

    if (i <= j)
    {
        printf("The %d-th larger number is %d\n", i, arr[j - i]);
    }
    else
    {
        printf("Error: i is out of range\n");
    }
}