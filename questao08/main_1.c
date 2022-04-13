#include <stdio.h>

int main() {

    int vet[] = {4,9,13}; // vet é inicializado.
    int i; //o contador é inciializado.

    for(i = 0; i < 3; i++) {
        printf("%d ",*(vet+i)); //o conteúdo na posição "i" do vetor "vet" é impresso.
    }
} // saída: "4 9 13 "