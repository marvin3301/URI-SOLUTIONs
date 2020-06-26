#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 1001 // maximo valor que N pode atingir

int sabores[MAX_N]; // vetor para armazenar os sabores dos mentos
int pd[MAX_N][MAX_N]; // matriz pra armazenar valores ja calculados(pd = programacao dinamica)

const int INF = 999999999; // contante para representar o valor infinito, no caso, o maior inteiro representavel.

int min(int a, int b){
    return (a<b)?a:b;
}
// funcao para calcular a solucao, onde a e b representa os indices dos extremos do tubo de mentos.
int solve(int a, int b) {
    if (a > b) return 0; // caso indices extrapolem, nenhuma escolha nesse caso.
    if (a == b) return 1;  // caso de indices na mesma posicao, so resta uma escolha neste caso.
    if (pd[a][b] != INF) return pd[a][b]; // se a solucao ja foi calculado retorna o valor armazenado

    int ret = INF; // ret representa o retorno das chamadas recursivas e inicia com infinito pra facilitar.
    // ret é atualizado com o minimo entre seu valor atual, infinito na primeira iteracao, 
    // com o resultado da chamada recursiva para opcao de selecionar o mentos do extremo da direita
    ret = min(ret, 1 + solve(a + 1, b)); 
    ret = min(ret, 1 + solve(a, b - 1)); // ret é atualizado com o minimo do valor atual com a chamada para escolha domentos do extremo da esquerda.

    // se os sabores nas pontas forem iguais, entao ele pega os dois sabores e a recursao é chamada para o restante.
    if (sabores[a] == sabores[b]) ret = min(ret, 1 + solve(a + 1, b - 1));

    pd[a][b] = ret; // armazena o valor do retorno ja calculado para a e b.
    return ret; // return o menor quantidade vezes que andre precisa parar pra pegar mentos, resultado para a e b.
}

// É recomendado utilizar memset ao inves de fill_n, pois opera a nivel de bit e por isso é mais eficiente, 
// mais tive problemas com memset por isso usei fill_n, que ainda assim é mais eficiente que 2 `for` aninhados.

int main() {

    int cases, n;
    scanf("%d",&cases); // lendo a quantidade de casos
    int i,t,j;

    for (t = 1; t <= cases; t++) {
        scanf("%d",&n); // lendo a quantidade de mentos no tubo

        for (i = 0; i < n; i++) scanf("%d",&sabores[i]);; // recebendo sabores dos mentos

        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                pd[i][j]=INF;
            }
        }
        // memset(pd, INF, sizeof(pd[0][0]) * n * n);

        printf("Caso #%d: %d\n",t,solve(0, n - 1)); // imprimindo a solucao para o t-esimo caso.
    }
    return 0;
}