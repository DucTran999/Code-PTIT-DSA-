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
			if(dfs(v,u)) return true;
		} else if(v != par) return true;
	}
	return false;
}

void isATree(int n) {
	for(int i = 1; i <= n; i++) {
		if(!met[i]) {
			if(dfs(i,0)) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		rs(G);
		rs(met);
		cin >> n;
		for(int i = 0; i < n-1; i++) {
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		isATree(n);
	}

	return 0;
}


