/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int const INF = 1e8;
int D[10005][10005];

void Floyd(int n) {
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <=n ; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}

void Init(int n) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			if(i != j) D[i][j] = INF;
			else D[i][j] = 0;
	}
}

void CountPath(int n) {
	cout << D[1][n] << " " << 2 << endl;
}

int main() {
	sync();
	int n, m , x, y, w;
	cin >> n >> m;
	Init(n);
	while(m--) {
		cin >> x >> y >> w;
		D[x][y] = D[y][x] = w;
	}
	Floyd(n);
	CountPath(n);
	return 0;
}


