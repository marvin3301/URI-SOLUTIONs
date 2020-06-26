#include <bits/stdc++.h>

using namespace std;

int a[101][101];

pair < int, int > spiralFill(int m, int n, int s) {
    int val = n * n * -1, k = 0, l = 0;

    while (k < m && l < n) {
        int d = val - s;
        if (-d <= n - l) {
            return make_pair(k, -d + l);
        } else {
            val += n - l;
        }

        k++;
        d = val - s;

        if (-d <= m - k) {
            return make_pair(-d + k, n - 1);
        } else {
            val += m - k;
        }

        n--;

        if (k < m) {
            d = val - s;
            if (-d < (n - l)) {
                return make_pair(m - 1, n - 1 + d);
            } else {
                val += n - l;
            }
            m--;
        }

        if (l < n) {
            d = val - s;
            if (-d < (m - k)) {
                return make_pair(m - 1 + d, l);
            } else {
                val += m - k;
            }
            l++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); // truque para ler entradas grandes.
    int n, s;

    while (cin >> n >> s) {

        pair < int, int > result = spiralFill(n, n, -s);

        int r = result.second;
        if (r == n / 2 || r == floor(n / 2)) {
            cout << result.first << " " << r << endl;
        } else {
            cout << result.first << " " << n - r - 1 << endl;
        }
    }
    return 0;
}
