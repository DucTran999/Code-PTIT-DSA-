/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
bool met[1005];

void dfs(int u) {
	met[u] = true;
	for(int v : G[u]) if(!met[v]) dfs(v);
}

int main() {
	sync();
	int t = 1, n, m, x, y, s;
//	cin >> t;
	while(t--) {
		rs(G);
		rs(met);
		cin >> n >> m >> s;
		while(m--) {
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(s);
		int ok = 0;
		for(int i = 1; i <= n; i++) {
			if(!met[i]) {
				cout << i << endl;
				ok = 1;
			}
		}
		if(ok == 0) cout << 0 << endl;
	}

	return 0;
}


