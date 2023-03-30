#include <stdio.h>

typedef int (*ADD_INT_Func) (int, int); 

int add (int x, int y) {
    return x + y; 
}

int sub (int x, int y) {
    return x - y; 
}

int mul (int x, int y) {
    return x * y; 
}

int div (int x, int y) {
    return x / y; 
}

int calc (ADD_INT_Func funcPtr, int x, int y) {
    return funcPtr(x, y);
}

int main () {
    printf("sum = %d\n", calc(add, 4, 2)); 
    printf("dif = %d\n", calc(sub, 4, 2)); 
    printf("product = %d\n", calc(mul, 4, 2)); 
    printf("quotient = %d\n", calc(div, 4, 2)); 
}
