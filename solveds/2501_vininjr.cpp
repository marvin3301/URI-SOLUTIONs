#pragma once
#pragma GCC optimize("O2") 

#include <bits/stdc++.h> // standard template library (STL)
#include <omp.h>

using namespace std;

typedef unsigned long long int ulli;

int primes[105];

ulli allowed_factors(int n, int m){

    priority_queue<ulli, vector<ulli>, greater<ulli>> pq;
    #pragma omp parallel for private(i)
    for(int i = 0; i < n; i++) pq.push(primes[i]);
    
    int count = 1;
    ulli no;
    while(count <= m){ 
        if(count==m) return pq.top();
        no = pq.top(); 
        pq.pop();
        while(no==pq.top()) pq.pop();
        #pragma omp parallel for private(i)
        for(int i = 0; i < n; i++) pq.push(no * primes[i]);
        count++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0); // truque para ler entradas grandes.
    int m,n;

    while(1)
    {
        cin >> n >> m;
        if(m==0 && n==0) break;

        for(int i=0; i<n; i++) cin >> primes[i];

        ulli result = (n==1) ? pow(primes[0], m): allowed_factors(n, m);
        cout << result << endl;
    }

    return 0;
}
