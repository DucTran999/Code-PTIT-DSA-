/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vector<set<int>> G(1005);
bool met[1005];
int trace[1005];

void dfs(int u) {
	if (trace[1] != 0)
		return;
	met[u] = true;
	for (auto v : G[u]) {
		if (!met[v]) {
			trace[v] = u;
			dfs(v);
		} else if (v == 1 && trace[u] != v) {
			trace[1] = u;
			return;
		}
	}
}

void findCycle(int e) {
	if (!e) {
		cout << "NO";
		return;
	}
	vi path;
	path.push_back(1);
	while (e != 1) {
		path.push_back(e);
		e = trace[e];
	}
	path.push_back(1);
	reverse(path.begin(), path.end());
	for(int i : path) cout << i << " ";
}

void hasCycle() {
	rs(met);
	rs(trace);
	dfs(1);
	findCycle(trace[1]);
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i<=n; i++) {
			G[i].clear();
		}
		while(m--) {
			cin >> x >> y;
			G[x].insert(y);
			G[y].insert(x);
		}
		hasCycle();
		cout << endl;
	}

	return 0;
}
