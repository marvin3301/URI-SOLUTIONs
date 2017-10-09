#include <stdio.h>


int ehPrimo(long long int N)
{
	long long int p;
	if(N==0 || N==1) return 0;
    for(p = 2; p*p <= N; p++)
        if(N % p == 0) return 0;
    return 1;
}


int ehSuper(long long int N){

	while(N>0){
		if(!ehPrimo(N % 10)) return 0;
			N/=10;
	}

	return 1;

}

int main()
{
	long long int n;
	while(scanf("%lld",&n)!=EOF){
		if(ehPrimo(n)){

			if(ehSuper(n)){
				printf("Super\n");
			}
			
			else{
				printf("Primo\n");
			}

		}

		else{
			printf("Nada\n");
		}

	}
	return 0;
}