#include <stdio.h>

int main(void){
    float vet[5] = {1.1,2.2,3.3,4.4,5.5}; // array de floats declarado e inicializado
    float *f; // ponteiro do tipo float (4 bytes) declarado.
    int i; // inteiro do contador declarado.
    f = vet; // endereço do array "vet" passado para o ponteiro "f".
    printf("contador/valor/valor/endereco/endereco");
    for (i = 0 ; i <= 4 ; i++) {
        printf("\ni = %d",i); // imprime o valor do contador em cada passagem.
        printf("vet[%d] = %.1f",i, vet[i]); // imprime qual posição do vetor estamos (vet[i]), e o número contido nesta posição.
        printf("*(f + %d) = %.1f",i, *(f+i)); // realiza o mesmo procedimento anterior mas usando incrementos no ponteiro "f" e retornando o conteúdo neste endereço.
        printf("&vet[%d] = %X",i, &vet[i]); // mostra o endereço em que cada elemento do vetor "vet" está guardado na memória.
        printf("(f + %d) = %X",i, f+i); // realiza o mesmo da linha anterior porém utilizando incrementos no ponteiro "f".
    }
}

// este código irá imprimir em cada linha os valores contidos na array "vet" utilizando tanto
// [] quando *() para retornar o conteúdo, demonstrando que ambas são válidas para este uso.
// Também imprimirá os endereços de cada posição usando tanto o operador de endereço "&" quanto
// imprimindo apenas o ponteiro incrementado do valor correspondente.