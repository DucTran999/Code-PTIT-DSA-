/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

const int INF = 1e6;
int D[101][101];

void Floyd(int n) {
	for(int i = 1; i <= n; i++) {
		D[i][i] = 0;
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
}

int main() {
	sync();
	int n, m , x, y, w, q;
	cin >> n >> m;
	for(int i = 1; i<=n; i++) {
		for(int j = 1; j <=n; j++) {
			D[i][j] = INF;
		}
	}
	while(m--) {
		cin >> x >> y >> w;
		D[x][y] = D[y][x] = w;
	}
	Floyd(n);
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << D[u][v] << endl;
	}

	return 0;
}


