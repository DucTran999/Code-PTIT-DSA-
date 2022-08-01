/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
bool met[1005];

bool dfs(int u, int par) {
	met[u] = true;
	for(int v : G[u]) {
		if(!met[v]) {
			if(dfs(v, u)) return true;
		} else if(v != par) return true;
	}
	return false;
}

void hasCycle(int n) {
	for(int i = 1; i <= n; i++) {
		if(!met[i]) {
			if(dfs(i,0)) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		rs(G);
		rs(met);
		while(m--) {
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		hasCycle(n);
	}

	return 0;
}


