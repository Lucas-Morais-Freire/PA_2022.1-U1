#include <stdio.h>
#include <stdlib.h>

void getMatrix(int*** M, int* pl, int* pc) {
    *pl, *pc = 0;
    if (*pl == 0) {
        printf("digite o numero de linhas da matriz: ");
        scanf("%d", pl);
        if (*pl < 1) {
            printf("entrada invalida");
            exit(0);
        }
    }
    printf("digite o numero de colunas da matriz: ");
    scanf("%d", pc);
    if (*pc < 1) {
        printf("entrada invalida");
        exit(0);
    }
    
    *M = malloc((*pl)*sizeof(int*));
    (*M)[0] = malloc((*pl)*(*pc)*sizeof(int));
    for (int i = 1; i < (*pl); i++) {
        (*M)[i] = (*M)[i - 1] + (*pc);
    }
    
    printf("Preencha as entradas da matriz: \n");
    for (int i = 0; i < *pl; i++) {
        for (int j = 0; j < *pc; j++) {
            printf("entrada [%d][%d]: ", i, j);
            scanf("%d", (*M)[i] + j);
        }
    }
}

void printMatrix(int** M, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multMatrix(int** A, int**  B, int** C, int la, int ca, int cb) {
    for(int i = 0; i < la; i++) {
        for (int j = 0; j < cb; j++) {
            C[i][j] = 0;
            for (int t = 0; t < ca; t++) {
                C[i][j] += A[i][t]*B[t][j];
            }
        }
    }
}

int main() {
    int** A;
    int la, ca = 0;
    
    printf("Criando a matriz A: \n");
    getMatrix(&A, &la, &ca);

    printf("A =\n");
    printMatrix(A, la, ca);

    int** B;
    int cb = 0;

    printf("Criando a matriz B: \n");
    getMatrix(&B, &ca, &cb);

    printf("B =\n");
    printMatrix(B, ca, cb);

    int** C = malloc(la*sizeof(int*));
    C[0] = malloc(la*cb*sizeof(int));
    for (int i = 1; i < la; i++) {
        C[i] = C[i - 1] + cb;
    }

    multMatrix(A, B, C, la, ca, cb);
    
    printf("A*B = C =\n");
    printMatrix(C, la, cb);

    free(A[0]);
    free(A);
    free(B[0]);
    free(B);
    free(C[0]);
    free(C);

    return 0;
}