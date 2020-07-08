#include <bits/stdc++.h>

using namespace std;
using Int = unsigned long long int;

unordered_set<Int> curr;
bool vis[100001];

void dfs(Int vertice, Int n, bool **vasos, Int k){
	if(k==0) return;
	vis[vertice]=1;
    for(int i = 1; i <= n; i++){
        if(vasos[i][vertice]==true && !vis[i]){
        	curr.insert(i);
            dfs( i, n, vasos, k-1);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0); // truque para ler entradas grandes.
	Int k,n,a,b;
	cin >> n >> k;
	
	bool **vasos = (bool**) malloc ((n+1)*sizeof(bool*));
	for(int j=0; j<=n; j++) vasos[j]=(bool*) malloc ((n+1)*sizeof(bool));

	for (int o = 1; o < n; o++)
	{
		cin >> a >> b;
		vasos[a][b] = vasos[b][a] = true;

	}

	for (int i = 1; i <= n; i++)
	{
		if(k<0){
			cout << n << endl;
		}
		else{
			dfs( i, n, vasos, k);
			Int result = curr.size();
			cout << result << endl;
			curr.clear();
			memset(vis, 0, (n+1)*sizeof(bool));
		}
	}
	
	return 0;
}