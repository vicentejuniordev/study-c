#include <stdio.h>
int multiply(int *x, int *y) {
    if (*y == 0) {
        return 0;
    } else {
        int temp = *y - 1;
        return *x + multiply(x, &temp);
    }
}

int main() {
    int x = 5;
    int y = 10;
    int result;
    result = multiply(&x, &y);
    printf("O produto de %d e %d eh: %d\n", x, y, result);
    return 0;
}