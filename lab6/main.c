#include <stdio.h>

int multi(int i, int j) {
    if (i == 1 && j == 1) {
        printf("%d*%d=%02d ", i, j, i*j); 
        return 0; 
    } else if (j == 1) {
        multi(i-1 , 9); 
        printf("\n%d*%d=%02d ", i, j, i*j);
    } else {
        multi(i, j-1); 
        printf("%d*%d=%02d ", i, j, i*j);
    }
}

int main()
{
    multi(9, 9); 
    return 0;
}
