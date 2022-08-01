#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

vi List[1005];
bool met[1005];
int trace[1005];

void DFS(int u) {
	met[u] = true;
	for(int &v : List[u]) {
		if(!met[v]) {
			trace[v] = u;
			DFS(v);
		}
	}
}

void findPath(int s, int e) {
	if(!trace[e]) {
		cout << -1;
		return;
	}
	vi path;
	while( e != s) {
		if(!e) {
			cout << -1;
			return;
		}
		path.push_back(e);
		e = trace[e];
	}
	path.push_back(e);
	reverse(path.begin(), path.end());
	for(int &i : path) cout << i << ' ';
}

int main() {
	sync();
	int t = 1, n, m, x, y, s, e;
	cin >> t;
	while(t--) {
		cin >> n >> m >> s >> e;
		memset(List, 0 , sizeof(List));
		memset(met, 0 , sizeof(met));
		memset(trace, 0 , sizeof(trace));
		while(m--) {
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		DFS(s);
		findPath(s, e);
		cout << endl;
	}

	return 0;
}


