#include <stdio.h>

int main () {
    FILE* fp1;
    FILE* fp2; 
    fp1 = fopen("main2.c", "r+");
    fp2 = fopen("main2.txt", "w+");

    char ch = fgetc(fp1);
    while (ch != EOF)
    {
        fputc(ch, fp2);
        ch = fgetc(fp1);
    }

    fclose(fp1);
    fclose(fp2);
}