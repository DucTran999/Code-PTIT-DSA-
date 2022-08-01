/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

const int maxn = 1e5, INF = 1e9;
vector<pair<int, int>> G[maxn];

void dijiktra(int n, int s) {

	vector<ll> d (n + 1, INF);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});

	while(!q.empty()) {
		pair<int, int> top = q.top();
		q.pop();
		int u = top.second;
		int len = top.first;
		if(len > d[u]) continue;
		for(auto it : G[u]) {
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({d[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
	cout << endl;
}

int main() {
	sync();
	int t = 1, n, m, s, x, y, w;
	cin >> t;
	while(t--) {
		rs(G);
		cin >> n >> m >> s;
		while(m--) {
			cin >> x >> y >> w;
			G[x].push_back({y, w});
			G[y].push_back({x, w});
		}
		dijiktra(n, s);
	}

	return 0;
}


