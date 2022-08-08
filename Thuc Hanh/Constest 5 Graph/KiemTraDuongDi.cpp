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

bool bfs(int u, int e) {
	queue<int> q;
	q.push(u);
	if(u == e) return true;
	met[u] = true;
	while(q.size()) {
		u = q.front();
		if(u == e) return true;
		q.pop();
		for(int v : List[u]) {
			if(!met[v]) {
				met[v] = true;
				q.push(v);
			}
		}
	}
	return false;
}

int main() {
	sync();
	int t = 1, n, m, q, s, e;
	cin >> t;
	while(t--) {
		rs(List);
		cin >> n >> m;
		while(m--) {
			int x, y;
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		cin >> q;
		while(q--) {
			rs(met);
			cin >> s >> e;
			if(bfs(s, e)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}


