#include <stdio.h>
int main(){
    int a = 10;
    int b = 20;
    int result = sum(&a, &b);
    printf("A soma de %d e %d eh: %d\n", a, b, result);
    return 0;
}

int sum(int *a, int *b){
    return *a + *b;
}