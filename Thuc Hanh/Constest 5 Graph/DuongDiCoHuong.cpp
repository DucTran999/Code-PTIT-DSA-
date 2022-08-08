/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

const int maxn = 1005;
vi List[maxn];
bool met[maxn];
int trace[maxn];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	met[u] = true;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		for(int v : List[u]) {
			if(!met[v]) {
				met[v] = true;
				trace[v] = u;
				q.push(v);
			}
		}
	}
}

void findPath(int s, int e) {
	if(!trace[e]) {
		cout << -1;
		return;
	}
	vi path;
	while(s != e) {
		if(!e) {
			cout << -1;
			return;
		}
		path.push_back(e);
		e = trace[e];
	}
	path.push_back(e);
	reverse(path.begin(), path.end());
	for(int i : path) cout << i << " ";
}

int main() {
	sync();
	int t = 1, n, m, s, e;
	cin >> t;
	while(t--) {
		rs(List);
		rs(met);
		rs(trace);
		cin >> n >> m >> s >> e;
		while(m--) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
		}
		bfs(s);
		findPath(s, e);
		cout << endl;
	}

	return 0;
}


