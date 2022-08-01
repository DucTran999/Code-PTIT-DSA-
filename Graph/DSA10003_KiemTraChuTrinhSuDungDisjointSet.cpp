/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vector<pair<int, int>> edge;
int par[1005];

int find(int u) {
	if(par[u] == -1)
		return u;
	return find(par[u]);
}

void Union(int parU, int parV) {
	par[parU] = parV;
}

bool isCycle() {
	int parU, parV;
	for(pair<int, int> e : edge) {
		parU = find(e.first);
		parV = find(e.second);
		if(parU == parV)
			return true;
		Union(parU, parV);
	}
	return false;
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		edge.clear();
		cin >> n >> m;
		for(int i = 1; i <= n; i++) par[i] = -1;
		while(m--) {
			cin >> x >> y;
			edge.push_back({x, y});
		}
		if(isCycle()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}


