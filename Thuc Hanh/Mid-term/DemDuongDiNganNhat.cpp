/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

const int INF = 1e9;
int D[10001][10001];

void init(int n) {
	for(int i = 1; i<=n; i++) for(int j = 1; j<=n; j++) D[i][j] = INF;
	for(int i = 1; i <= n; i++) D[i][i] = 0;
}

void Floyd(int n) {
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
			}
		}
	}
}

int main() {
	sync();
	int t = 1, n, m;
//	cin >> t;
	while(t--) {
		cin >> n >> m;
		init(n);
		while(m--) {
			int x, y, w;
			cin >> x >> y >> w;
			D[x][y] = w;
			D[y][x] = w;
		}
		Floyd(n);
	}

	return 0;
}


