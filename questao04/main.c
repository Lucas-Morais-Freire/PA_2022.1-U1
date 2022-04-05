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

  /* (g) */
  p3--;
  printf("%c \n", *p3);

  /* (h) */
  vetor[0] = 31;
  vetor[1] = 45;
  vetor[2] = 27;
  p4 = vetor;
  idade = *p4;
  printf("%d \n", idade);

  /* (i) */
  p5 = p4 +1;
  idade = *p5;
  printf("%d \n", idade);

  /* (j) */
  p4 = p5 + 1;
  idade = *p4;
  printf("%d \n", idade);

  /* (l) */
  p4 = p4 - 2;
  idade = *p4;
  printf("%d \n", idade);

  /* (m) */
  p5 = &vetor[2] - 1;
  printf("%d \n", *p5);
  
  /* (n) */
  p5++;
  printf("%d \n", *p5);
  return(0);
}