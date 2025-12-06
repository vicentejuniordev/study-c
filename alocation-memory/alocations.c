#include <stdio.h>


int main() {

    puts("Vetor com alocação estático na stack memory");

    int vs[5] = {10,20,30,40,50};

    printf("&vs = %p - vs = %p", &vs, vs);

    return 0;
}