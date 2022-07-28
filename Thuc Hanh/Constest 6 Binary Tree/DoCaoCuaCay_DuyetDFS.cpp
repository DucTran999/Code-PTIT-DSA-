#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

const int maxn = 1e5+5;
vi List[maxn];
bool met[maxn];
int trace[maxn];

inline int max(int a, int b) {
	return (a > b) ? a :  b;
}

void dfs(int u) {
	met[u] = true;
	for(int &v : List[u]) {
		if(!met[v]) {
			trace[v] = u;
			dfs(v);
		}
	}
}

void findPath(int s, int e, int& depth) {
	if(trace[e] == 0) return;
	vi path;
	while(s != e) {
		if(!e) return;
		path.push_back(e);
		e = trace[e];
	}
	depth = max(depth, path.size());
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		memset(List, 0, sizeof(List));
		memset(met, 0, sizeof(met));
		memset(trace, 0, sizeof(trace));
		for(int i = 1; i < n; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
		}
		dfs(1);
		int depth = INT_MIN;
		for(int i = 2; i <= n ; i++) {
			findPath(1, i, depth);
		}
		cout << depth << endl;
	}

	return 0;
}


