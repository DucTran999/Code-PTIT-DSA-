/* Contributed by: DucNTA */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
int state[1005];

bool dfs(int u) {
	state[u] = 1;
	for(int v : G[u]) {
		if(state[v] == 0) {
			if(dfs(v)) return true;
		} else if(state[v] == 1) return true;
	}
	state[u] = 2;
	return false;
}

void hasCycle(int n) {
	int ok = 0;
	for(int i = 1; i <= n; i++) {
		if(state[i] == 0) {
			if(dfs(i)) {
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
		rs(G);
		rs(state);
		cin >> n >> m;
		while(m--) {
			cin >> x >> y;
			G[x].push_back(y);
		}
		hasCycle(n);
	}

	return 0;
}


