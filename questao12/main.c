#include <stdio.h>
#include <stdlib.h>

int func_1(int a, int b) { //retorna a + b
    return a + b;
}

int func_2(int a, int b) { //retorna a*b
    return a*b;
}

int func_3(int a, int b) { //retorna a^b
    int res = 1;
    for (int i = 0; i < b; i++) {
        res *= a;
    }
    return res;
}

int main() {

    int (*p1)(int, int) = &func_1; // para se criar um ponteiro para uma funcao, usa-se esta sintaxe. O ponteiro irá apontar para o início do bloco da memória onde as instruções da função estão localizadas.
    int res = (*p1)(1, 2); // usando o ponteiro criado, podemos chamar a funcao derreferenciando o ponteiro e passando os parametros.
    printf("%d\n", res); //assim, podemos imprimir o resultado.

    int (*pf[3])(int, int); // outro uso para ponteiros de funções seria criar um vetor de funções, assim podemos guardar as operações que precisamos em uma única variável e acessá-las facilmente
    pf[0] = &func_1; //coloco o endereço de cada função nas posições do array
    pf[1] = &func_2;
    pf[2] = &func_3;

    printf("%d", (*pf[0])(3, 2) + (*pf[1])(3, 2) + (*pf[2])(3, 2)); //podemos chamar cada função desta maneira. Aqui imprimo (3+2) + (3*2) + (3^2) = 20

    return 0;
}