/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

vector<pair<int, int >> edge;
int par[1005];

int find(int u) {
	if(u == par[u]) return u;
	return par[u] = find(par[u]);
}

void Union(int parU, int parV) {
	par[parU] = parV;
}

void maxSubset(int n) {
	set<int> subSet;
	for(pair<int, int> e : edge) {
		int parU = find(e.first);
		int parV = find(e.second);
		if (parU != parV) {
			Union(parU, parV);
		}
	}
	for (int i = 1; i <= n; i++) {
		subSet.insert(find(par[i]));
	}
	cout << subSet.size() << endl;
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		edge.clear();
		cin >> n >> m;
		for(int i = 1; i <= n; i++) par[i] = i;
		while(m--) {
			cin >> x >> y;
			edge.push_back({x, y});
		}
		maxSubset(n);
	}

	return 0;
}


