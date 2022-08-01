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
	for(int &v : List[u])
		if(!met[v]) {
			trace[v] = u;
			DFS(v);
		}
}

void findPath(int s , int e) {
	if(!trace[e]) {
		cout << -1;
		return;
	}
	vi res;
	while(e != s) {
		if(e == 0) {
			cout << -1;
			return;
		}
		res.push_back(e);
		e = trace[e];
	}
	res.push_back(e);
	reverse(res.begin(), res.end());
	for(int &i : res) cout << i << ' ';
}

int main() {
	sync();
	int t = 1, n, m, x, y, u , v;
	cin >> t;
	while(t--) {
		memset(List, 0, sizeof(List));
		memset(met, 0, sizeof(met));
		memset(trace, 0, sizeof(trace));
		cin >> n >> m >> u >> v;
		while(m--) {
			cin >> x >> y;
			List[x].push_back(y);
		}
		DFS(u);
		findPath(u, v);
		cout << endl;
	}

	return 0;
}


