#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char x[4]; //tamanho de variável char: 1 byte.
    int i;
    printf("endereco inicial: %d\n", x);
    for (i = 1; i < 4; i++) {
        printf("x + %d: %d\n", i, x + i);
    }
    printf("\n");

    short y[4]; //tamanho de variável short: 2 bytes.
    printf("endereco inicial: %d\n", y);
    for (i = 1; i < 4; i++) {
        printf("y + %d: %d\n", i, y + i);
    }
    printf("\n");

    float z[4]; //tamanho de variável float: 4 bytes.
    printf("endereco inicial: %d\n", z);
    for (i = 1; i < 4; i++) {
        printf("z + %d: %d\n", i, z + i);
    }
    printf("\n");

    double w[4]; //tamanho de variável double: 8 bytes.
    printf("endereco inicial: %d\n", w);
    for (i = 1; i < 4; i++) {
        printf("w + %d: %d\n", i, w + i);
    }
    printf("\n");

    return 0;
}
