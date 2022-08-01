/* Contributed by Anh Duc*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
bool met[1005];
vector<pair<int, int >> edge;

void dfs(int u) {
	met[u] = true;
	for(int v : G[u]) {
		if(!met[v])
			dfs(v);
	}
}
void dfs2(int u, int x, int y) {
	met[u] = true;
	for(int v : G[u]) {
		if((u == x and v == y) or (u == y and v == x)) continue;
		if(!met[v]) dfs2(v, x, y);
	}
}

void findBridge(int n) {
	rs(met);
	int tplt = 0;
	for(int i = 1; i <= n; i++) {
		if(!met[i]) {
			tplt++;
			dfs(i);
		}
	}

	for(auto e : edge) {
		int x = e.first, y = e.second;
		rs(met);
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(!met[j]) {
				++cnt;
				dfs2(j,x,y);
			}
		}
		if(cnt > tplt) cout << x << " " << y << " ";
	}
	cout << endl;
}

int main() {
	sync();
	int t = 1, n, m;
	cin >> t;
	while(t--) {
		rs(G);
		edge.clear();
		cin >> n >> m;
		while(m--) {
			int x, y;
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
			edge.push_back({x,y});
		}
		findBridge(n);
	}
	return 0;
}
