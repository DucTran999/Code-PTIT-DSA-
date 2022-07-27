#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

vi List[1005];
bool met[1005];
int trace[1005];

void dfs(int u) {
	met[u] = true;
	for(int v : List[u]) {
		if(!met[v]) {
			trace[v] = u;
			dfs(v);
		}
	}
}

void findPath(int s, int e) {
	vi path;
	while(s != e) {
		path.push_back(e);
		e = trace[e];
	}
	cout << path.size() << endl;
}

int main() {
	sync();
	int t = 1, n, q;
	cin >> t;
	while(t--) {
		memset(List, 0, sizeof(List));
		cin >> n;
		for(int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		cin >> q;
		while(q--) {
			int s, e;
			cin >> s >> e;
			memset(met, 0, sizeof(met));
			memset(trace, 0, sizeof(trace));
			dfs(s);
			findPath(s, e);
		}
	}

	return 0;
}


