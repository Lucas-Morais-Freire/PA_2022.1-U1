#include <stdio.h>

int main() {

    int vet[] = {4,9,13}; // vetor "vet" é inicializado.
    int i; // contador inicializado.

    for(i = 0; i < 3; i++) {
        printf("%X ", vet + i); // o endereço (em hexadecimal) da iésima posição do vetor "vet"
    }
} //saída: "61FE10 61FE14 61FE18 "

