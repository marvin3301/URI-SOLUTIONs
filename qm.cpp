#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Pais{
	char nome[100];
	int ouro, prata, bronze;
};

int compara( const void *p1, const void *p2 ){
	struct Pais *i = (struct Pais *)p1, *j = (struct Pais *)p2;
	if(i->ouro < j->ouro)
		return 1;
	else if(i->ouro > j->ouro)
		return -1;
	else
		if(i->prata < j->prata)
			return 1;
		else if(i->prata > j->prata)
			return -1;
		else if(i->bronze < j->bronze)
			return 1;
			else if(i->bronze > j->bronze)
				return -1;
			else strcmp(i->nome, j->nome);
}

int main(){
	int n, i;

	scanf("%d", &n);

	struct Pais pais[n];

	for(i = 0; i < n; i++)
		scanf("%s %d %d %d", &pais[i].nome, &pais[i].ouro, &pais[i].prata, &pais[i].bronze);

	qsort(pais, n, sizeof(struct Pais), compara);

	for(i = 0; i < n; i++)
		printf("%s %d %d %d\n", pais[i].nome, pais[i].ouro, pais[i].prata, pais[i].bronze);

	return 0;
}

