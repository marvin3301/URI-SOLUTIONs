#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main (){

  int i,l, c, r, anterior, atual;
  unsigned long int movimentos=0, m;
  vector<unsigned long int> saida;

  while (cin>>m && m>0){/*Enquanto o usuário não digita 0 na entrada...*/
  i=0;
  /*Pista esquerda -> 1, Pista central -> 2 e Pista direita -> 3*/
  anterior=2; /*Começa na pista central*/
  movimentos=0; /*Reseta a contagem de movimentos*/
  while (i<m){/*Enquanto estiver recebendo entrada...*/
      cin >> l >> c >> r;
      if (l == 1 || c == 1 || r == 1){/*...verifique se alguma das entradas é igual a 1*/
	  /*Se tiver entrada igual a 1, somente uma delas é igual a zero. Papai noel deve ir para a pista 
	  correspondente ao 0.*/
	  if (l == 0){atual=1;}
	  else{if (c == 0){atual=2;}
	       else{atual=3;}}
      movimentos+=(abs(atual-anterior));
      anterior=atual;}
      i++;}
    /*Coloca o número de movimentos de caso de teste num vetor de saída*/
    saida.push_back(movimentos);}
    
    /*Imprime o resultado */
    for(i=0;i<saida.size();i++){
        cout << saida[i] << "\n";
    }
  return 0;
}