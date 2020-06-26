#include "bits/stdc++.h"

using namespace std;
using Int = unsigned long long int;

#define MOD 86400

Int StringModToInt(string num) {
    Int res = 0;
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (Int) num[i] - '0') % MOD;
    return res;
}

Int binpow(Int a, Int b) {
    if (b == 0) return 1;
    Int res = 1;
    while (b > 1) {
        if (b & 1) {
            res = (res * (a % MOD)) % MOD;
        }
        a *= a % MOD;
        a %= MOD;
        b >>= 1;
    }
    return ((a % MOD) * (res % MOD)) % MOD;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string x_;
    cin >> x_;
    Int x = binpow(2, StringModToInt(x_)) - 1;
    Int A = x / 3600;
    x %= 3600;
    Int B = x / 60;
    Int C = x % 60;
    cout.fill('0');
    cout << setw(2) << A << ":" << setw(2) << B << ":" << setw(2) << C << endl;
    return 0;
}