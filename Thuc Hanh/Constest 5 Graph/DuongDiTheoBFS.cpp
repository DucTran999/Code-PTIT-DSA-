/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi List[1005];
bool met[1005];
int trace[1005];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	met[u] = true;
	while(q.size()) {
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

void bfs(int u) {
	queue<int> q;
	q.push(u);
	met[u] = true;
	while(q.size()) {
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
		cout <<"No path";
		return;
	}
	vi path;
	while(s != e) {
		if(!e) {
			cout <<"No path";
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
	int t = 1, n, m, s, x, y;
	cin >> t;
	while(t--) {
		rs(List);
		rs(met);
		rs(trace);
		cin >> n >> m >> s;
		while(m--) {
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		bfs(s);
		for(int i = 1; i<=n; i++) {
			if(i != s) {
				findPath(s, i);
				cout << endl;
			}
		}
	}
	return 0;
}


