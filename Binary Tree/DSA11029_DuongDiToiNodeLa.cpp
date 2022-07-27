#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

vi List[1005];
bool met[1005];
int trace[1005];
int degree[1005];
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
	if(degree[e] > 1) return;
	if(trace[e] == 0) {
		return;
	}
	vi path;
	while(s != e) {
		if(!e) {
			return;
		}
		path.push_back(e);
		e = trace[e];
	}
	path.push_back(e);
	reverse(path.begin(), path.end());
	for(int i : path) cout << i << ' ';
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		memset(List, 0, sizeof(List));
		memset(met, 0, sizeof(met));
		memset(trace, 0, sizeof(trace));
		memset(degree, 0, sizeof(degree));
		cin >> n;
		for(int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
			degree[x]++;
			degree[y]++;
		}
		dfs(1);
		for(int i = 2; i <= n; i++) {
			findPath(1, i);
			cout << endl;
		}
	}

	return 0;
}


