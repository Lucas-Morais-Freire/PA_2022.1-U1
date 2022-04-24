#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printbyte(unsigned char c){
  unsigned char i;
  unsigned char and;
  for(i = 128; i > 0; i = i >> 1){
    and = i & c;
    if(and){
      printf("1");
    }
    else{
      printf("0");
    }
  }
}

float randomf() { // funcao que me gera um float aleatorio (necessita de stdlib.h, string.h e time.h)
  unsigned int* random = malloc(sizeof(unsigned int)); //alocar memoria para guardar um valor inteiro
  *random = 0; // inicializá-lo como sendo 0
  unsigned short record[32]; //criar um vetor que guardará primeiramente todos os bits a fim de facilitar testes

  short i; // inicializar contador
  
  unsigned char redo;
  do { //vou gerar uma sequencia de 32 bits aleatorios, se essa sequencia nao for valida, esse loop ira se repetir.
    redo = 0; // se eu voltar para este ponto, esta variavel deve estar como zero.
    for (i = 31; i >= 0; i--) {
        record[i] = rand() % 2;
    }
    
    //primeiro, testar se o numero é um zero negativo:
    unsigned char test = 1; // inicializarei uma variavel de teste
    if (record[0] == 1) { //para isso, o primeiro bit é 1
      for (int j = 1; j < 32; j++) { //testarei os bits restantes do numero
        if (record[j] == 1) { // se eu encontrar algum bit ligado
          test = 0; //isso significa que eu nao tenho um zero negativo, entao nao precisarei mudar nada.
        }
      }
      if (test) { // se nao encontrei mais nenhum bit ligado, entao temos um zero negativo
        redo = 1; // e refaço o loop.
      }
    }
    
    //depois testar se é um NaN:

    test = 1; // inicializarei uma variavel para os testes
    for (int j = 1; j <= 8; j++) { // vou checar os bits que fazem parte do expoente.
      if (record[j] == 0) { //se todos estiverem ligados, este if nao sera executado, porem se tivermos pelo menos um zero:
        test = 0; // isso significa que nao temos um NaN, entao nao precisamos realizar o teste seguinte.
        break; // podemos tambem sair deste loop.
      }
    }
    if (test) { // se todos os bits do expoente estiverem ligados, é possivel que tenhamos um NaN.
      test = 0; // assumirei que todos os bits restantes do numero sao zeros
      for (int j = 9; j < 32; j++) { //agora, precisamos testar os bits restantes do numero.
        if (record[j] == 1) { // se encontrarmos algum bit ligado, temos um NaN
          test = 1;
          break;
        }
      }
      if (test) {
        redo = 1; // agora, sinalizarei para o loop que ele deve repetir
      }
    }
  } while (redo);

  for (i = 31; i >= 0; i--) { // quando eu gero um float valido, posso escrever os bits em um valor inteiro
    *random += ((unsigned int)(record[i])) << 31 - i;
  }

  float* pf = malloc(sizeof(float)); //alocar memoria para guardar um valor float
  memcpy(pf, random, 4); // e copio  os bits do inteiro para o float.

  free(random); //libero a memoria alocada pelo inteiro

  float res = *pf; // copio o valor do float para uma variavel de saida

  free(pf); //libero a memoria alocada pelo float

  return res; // retorno o float
}

void bubbleSort(float* f, short n) {
  if (n == 1) {
    return;
  }

  float temp;
  for (int i = 0; i < n - 1; i++) {
    if (f[i + 1] < f[i]) {
      temp = f[i];
      f[i] = f[i + 1];
      f[i + 1] = temp;
    }
  }

  bubbleSort(f, n - 1);
}

int main() {

    srand(time(NULL));
    short n;
    
    printf("digite quantos valores tera o seu array de floats (valor maximo: 10000): ");
    scanf("%hd", &n);
    if (n <= 0 || n > 10000) {
        printf("entrada invalida!");
        exit(0);
    }

    float* nums = malloc(n*sizeof(float));
    for (int i = 0; i < n; i++) {
      nums[i] = randomf();
    }

    for (int i = 0; i < n; i++) {
      printf("%0.60f\n", nums[i]);
    }
    printf("\n");

    bubbleSort(nums, n);

    for (int i = 0; i < n; i++) {
      printf("%0.60f\n", nums[i]);
    }
    printf("\n");

    return 0;
}