#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[] = {1, 2, 3};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3}; 
    int arr_read[3]; 

    FILE* fp;
    fp = fopen("a.bin", "wb+");
    fwrite(a, sizeof(a), 1, fp);
    fseek(fp, 0, SEEK_SET);
    fread(arr_read, sizeof(arr_read), 1, fp);

    for (int i = 0; i < sizeof(arr_read); i++) {
        printf("%d ", arr_read[i]);
    }

    fclose(fp);
}