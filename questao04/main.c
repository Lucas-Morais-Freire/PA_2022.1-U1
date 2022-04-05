#include <stdio.h>

int main() {
  int valor;
  int *p1;
  float temp;
  float *p2;
  char aux;
  char *nome = "Ponteiros";
  char *p3;
  int idade;
  int vetor[3];
  int *p4;
  int *p5;

  /* (a) */
  valor = 10;
  p1 = &valor;
  *p1 = 20;
  printf("%d \n", valor);

  /* na saída irá aparacer 20, pois o conteúdo da variável "valor" foi alterado visto que "p1" apontava
  para a variável "valor", e o conteúdo desta foi alterado para 20. */

  /* (b) */
  temp = 26.5;
  p2 = &temp;
  *p2 = 29.0;
  printf("%.1f \n", temp);

  /* na saída aparecerá 29.0, já que o conteúdo da variável "temp" foi alterado para 29.0 na linha 28
  ao atribuírmos ao conteúdo de p2 (que é o valor guardado em temp). só aparecerá uma casa decimal pois
  na linha 29 foi especificado o número de casas decimais (%.1f) */

  /* (c) */
  p3 = &nome[0];
  aux = *p3;
  printf("%c \n", aux);

  /* "p3" recebe o endereço para o primeiro byte da string "nome", cujo conteúdo é o primeiro caractere
  desta string ("P"). assim, foi impresso este caractere ao guardar em "aux" o conteúdo de p3, que é
  este caractere. */

  /* (d) */
  p3 = &nome[4];
  aux = *p3;
  printf("%c \n", aux);

  /* mesma lógica da questão anterior, porém foi guardado o endereço cujo conteúdo é o quinto caractere
  da string "nome", que é a letra "e". */

  /* (e) */
  p3 = nome;
  printf("%c \n", *p3);

  /* quase a mesma coisa do item (c), porém ao invés de mais legivelmente guardarmos o endereço
  do primeiro caractere da string "Ponteiros", foi passado diretamente o endereço guardado em "nome"
  para p3, que também aponta para o começo da string. Assim, foi impresso mais uma vez o primeiro
  caractere da string, que é o "P". */

  /* (f) */
  p3 = p3 + 4;
  printf("%c \n", *p3);

  /* O ponteiro "p3" foi declarado como apontando para uma variável do tipo char, que tem tamanho de
  1 byte. Neste momento, p3 está apontando para o primeiro caractere da string "Ponteiros", e ao
  incrementá-lo por 4 bytes, ele aponta para o endereço 4 bytes adiante do primeiro caractere, ou seja,
  para o quinto caractere da string; neste caso, a letra "e", que foi impressa. */

  /* (g) */
  p3--;
  printf("%c \n", *p3);

  /* Ao ser decrementado em uma unidade, "p3" aponta para o endereço 3 bytes adiante do primeiro
  caractere da string "Ponteiros", ou seja, aponta para o endereço onde está guardada a letra "t",
  que foi impressa. */

  /* (h) */
  vetor[0] = 31;
  vetor[1] = 45;
  vetor[2] = 27;
  p4 = vetor;
  idade = *p4;
  printf("%d \n", idade);

  /* O ponteiro "vetor" guarda o endereço do primeiro elemento da array. ao atribuir este endereço à
  "p4", e em seguida o conteúdo deste endereço em "idade", estaremos guardando o inteiro "31" nesta
  última variável. Ao imprimí-la, constata-se isso. */

  /* (i) */
  p5 = p4 +1;
  idade = *p5;
  printf("%d \n", idade);

  /* Aqui, o ponteiro "p5" guarda o mesmo endereço de "p4", incrementado de 1. como "p5" foi declarado
  como ponteiro de inteiro, isto o fará apontar para o endereço 4 bytes adiante de p4, onde se localiza
  o próximo inteiro da array "vetor". ou seja, aponta para onde o número "45" foi guardado, que foi
  impresso. */

  /* (j) */
  p4 = p5 + 1;
  idade = *p4;
  printf("%d \n", idade);

  /* Aqui, a variável "idade" guarda o conteúdo do endereço "p4", este que agora terá o endereço do
  próximo inteiro na array "vetor" em relação ao p5. Neste caso, este endereço aponta para o número
  27, que foi impresso ao atribuir o conteúdo de "p4" para a variável "idade" e imprimindo-a.  */

  /* (l) */
  p4 = p4 - 2;
  idade = *p4;
  printf("%d \n", idade);

  /* "p4" foi decrementado em duas unidades, no bloco de código anterior, ele apontava para a terceira
  posição do array "vetor", agora ele volta a apontar para a primeira, que guarda o número 31, que foi
  impresso usando o mesmo método do item anterior. */

  /* (m) */
  p5 = &vetor[2] - 1;
  printf("%d \n", *p5);
  
  /* o endereço da segunda posição da array "vetor" aponta para o número 27; ao decrementá-lo em
  uma unidade, este ponteiro aponta para a posição anterior da array, que neste caso contém o número
  45. */

  /* (n) */
  p5++;
  printf("%d \n", *p5);

  /* ao incrementar o ponteiro p5 em uma unidade, considerando que antes ele apontava para a segunda
  posição do array "vetor", agora ele estará apontando para a terceira posição, que contém o número
  27. */

  return(0);
}