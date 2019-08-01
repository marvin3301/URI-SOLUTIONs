#include <stdio.h>

int main(){

	int a,b,c,i,j,k,l;
	scanf("%d%d%d",&a,&b,&c);
	j=4*a+2*b;
	k=2*a+2*c;
	l=4*c+2*b;
	
	if(j<=k && j<=l){
		printf("%d\n",j);
}	else if(k<=j && k<=l){
		printf("%d\n",k);

}	else if(l<=j && l<=k){
		printf("%d\n",l);
}

	



return 0;
} 

