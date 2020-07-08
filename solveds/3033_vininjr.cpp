// https://www.urionlinejudge.com.br/judge/pt/problems/view/3033

#include<bits/stdc++.h>

using namespace std;

typedef vector<pair<int,int>> Grid;
typedef Grid::iterator point;

#define forEach(it, grid) for (it = grid.begin(); it != grid.end(); it++)
#define YES "Y"
#define NO "N"

inline bool check_point_in_rectangle(point p1, point p, point p2) {
	return (min(p1 -> first,p2 -> first) <= p -> first && p -> first <= max(p1 -> first,p2 -> first)) && 
		   (min(p1 -> second,p2 -> second) <= p -> second && p -> second <= max(p1 -> second,p2 -> second));
}

bool check(point p1, point p2, Grid &grid) {
    if (p1 -> first == p2 -> first || p1 -> second == p2 -> second) return true;
    point p;
    forEach(p, grid) {
        if (p != p1 && p != p2 && check_point_in_rectangle(p1, p, p2)) return true;
    }
    return false;
}

string solve(Grid &grid) {
	point p1, p2;
    forEach(p1, grid) {
        forEach(p2, grid) {
            if (p1 != p2 && !check(p1, p2, grid)) return NO;
        }
    }
    return YES;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); // truque para ler entradas grandes
    int m, n, p, x, y;
    Grid grid;

    while (cin >> n >> m >> p) {

        while (p--) {
            cin >> x >> y;
            grid.push_back(make_pair(x, y));
        }

        cout << solve(grid) << endl;
        grid.clear();
    }
    return 0;
}