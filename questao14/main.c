#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

float randomf() { // funcao que me gera um float aleatorio (necessita de stdlib.h, string.h e time.h)
  unsigned int* random = malloc(sizeof(unsigned int)); //alocar memoria para guardar um valor inteiro
  *random = 0; // inicializá-lo como sendo 0

  int i; // inicializar contador
  int j = rand() % 8 + 1; // inicializar um numero aleatorio de 1 a 8 para ser a posicao de um zero obrigatorio. isto serve para impedir que o float gerado seja um NaN ou +/-infinito.
  
  for (i = 31; i >= 1; i--) { // agora, escrever bits aleatorios no numero
    if (i != j) { //apenas se nao estivermos na posicao aleatoria especial definida anteriormente, mas se estivermos, deixaremos como sendo zero.
      *random += (rand() % 2) << (31 - i);
    }
  }
  if(*random) { // se o numero nao for zero a este ponto
    *random += (rand() % 2) << 31; //podemos preencher o ultimo bit com qualquer valor. Se nao deixamos como sendo o zero.
  } //isto serve para impedir que o numero gerado seja um zero negativo.
  
  float* pf = malloc(sizeof(float)); //alocamos memoria para o float para poder
  memcpy(pf, random, 4); //copiar os bits do inteiro para o float
  free(random); //depois disso, podemos liberar a memoria do inteiro
  float res = *pf; //copiar o resultado para uma variavel de saida
  free(pf); //liberar a memoria do inteiro
  return res; // e retornar o float que foi gerado.
}

int cmp(const void* a, const void* b) {
  if (*(float*)a < *(float*)b) { // se a vem antes de b, retornar um valor negativo.
    return -1;
  } else if (*(float*)a == *(float*)b) { // se a é equivalente a b, retornar 0.
    return 0;
  } else { //se não, é porque a é maior que b. Neste caso, retornar um valor negativo.
    return 1;
  }
}

int main() {

  srand(time(NULL)); // iniciaização da seed para os números aleatórios.
  short n = 0; // número que guardará o tamanho do array de floats.
  
  printf("digite quantos valores tera o seu array de floats (valor maximo: 10000): "); //solicitando o valor de n do usuário.
  scanf("%hd", &n); //colocando em n o valor lido.
  if (n <= 0 || n > 10000) { //testando se o número é válido (tamanho não pode ser negativo, e também não seria interessante se fosse muito muito alto.)
      printf("entrada invalida!"); //sinalizar para o usuário que ele inseriu um valor inválido.
      exit(0); //finalizar o programa.
  }

  float* nums = malloc(n*sizeof(float)); // alocando memória para o array.
  for (int i = 0; i < n; i++) { // loop para preencher os valores guardados em "nums"
    nums[i] = randomf(); // colocando na iésima posição um float aleatório.
    printf("%0.60f\n", nums[i]); //imprimo na tela o valor guardado  nessa iésima posição (para comparar com a lista ordenada posteriormente)
  }
  printf("\n");

  qsort(nums, n, sizeof(float), cmp); // implemento a função qsort, usando a função "cmp" para comparar.

  for (int i = 0; i < n; i++) { //loop para imprimir novamente o vetor (dessa vez ordenado)
    printf("%0.60f\n", nums[i]);
  }
  printf("\n");

  return 0;
}