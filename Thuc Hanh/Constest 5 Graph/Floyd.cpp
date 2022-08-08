/* Contributed by: Anh Duc */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000, INF = 1e5;
int D[maxn][maxn];

void Floyd(int n) {
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n ; i++) {
			for(int j = 1; j <= n; j++) {
				if(D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}

void Init(int n) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			if(i != j) D[i][j] = INF;
			else D[i][j] = 0;
	}
}

int main() {
	int n, m , x, y, w, q, u, v;
	cin >> n >> m;
	Init(n);
	while(m--) {
		cin >> x >> y >> w;
		D[x][y] = D[y][x] = w;
	}
	Floyd(n);
	cin >> q;
	while(q--) {
		cin >> u >> v;
		cout << D[u][v] << endl;
	}

	return 0;
}
