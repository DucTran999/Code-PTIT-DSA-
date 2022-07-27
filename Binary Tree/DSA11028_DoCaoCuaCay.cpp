#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

vi List[100005];
bool met[100005];
int trace[100005], depth;

int max(int a, int b) {
	return (a > b) ? a : b;
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

void findPath(int s, int e) {
	if(!trace[e]) {
		return;
	}
	vi path;
	while( e != s) {
		if(!e) {
			return;
		}
		path.push_back(e);
		e = trace[e];
	}
	path.push_back(e);
	depth= max(path.size(), depth);
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		depth = INT_MIN;
		cin >> n;
		memset(List, 0, sizeof(List));
		memset(met, 0, sizeof(met));
		memset(trace, 0, sizeof(trace));
		for(int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
		}
		dfs(1);
		for(int i = 2; i <= n; i++) {
			findPath(1,i);
		}
		cout << depth - 1 << endl;
	}
	return 0;
}


