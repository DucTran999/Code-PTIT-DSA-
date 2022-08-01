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

bool findPath(int s, int e) {
	if(!trace[e]) {
		return false;
	}
	while(e != s) {
		if(!e) {
			return false;
		}
		e = trace[e];
	}
	return true;
}

int main() {
	sync();
	int t = 1, n, m, x, y, s, e, q;
	cin >> t;
	while(t--) {
		cin >>  n >> m;
		memset(List, 0 ,sizeof(List));
		while(m--) {
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		cin >> q;
		while(q--) {
			cin >> s >> e;
			memset(met, 0 ,sizeof(met));
			memset(trace, 0 ,sizeof(trace));
			DFS(s);
			if(findPath(s, e)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}


