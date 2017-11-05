#include <iostream>
#include <algorithm>

using namespace std;

int cmp(int a,int b){
	return a>b;
}

int main(int argc, char const *argv[])
{
	int n,q,p;

	while(cin>>n>>q){

		int vet[n];

		for (int i = 0; i < n; i++)
		{
			cin>>vet[i];
		}

		sort(vet,vet+n,cmp);

		for(int i=0;i<q;i++)
		{
			cin>>p;
			cout<<vet[p-1]<<endl;
		}

	}
	
	return 0;
}
