#include <stdio.h>
#include <stdlib.h>

void sumVect(const int* v1, const int* v2, int* res, const int n) {
    for (int i = 0; i < n; i++) {
        res[i] = v1[i] + v2[i];
    }
}

int main() {
    int n = 0;
    printf("digite o numero de elementos que os vetores irao conter: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("entrada invalida!");
        exit(0);
    }

    int* v1 = malloc(n*sizeof(int));
    int* v2 = malloc(n*sizeof(int));
    int* res = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("digite o elemento na posicao %d do primeiro vetor: ", i + 1);
        scanf("%d", v1 + i);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("digite o elemento na posicao %d do segundo vetor: ", i + 1);
        scanf("%d", v2 + i);
    }
    printf("\n");

    sumVect(v1, v2, res, n);

    printf("v1 + v2 = [");
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d]", res[i]);
        } else {
            printf("%d, ", res[i]);
        }
    }

    free(v1);
    free(v2);
    free(res);

    return 0;
}