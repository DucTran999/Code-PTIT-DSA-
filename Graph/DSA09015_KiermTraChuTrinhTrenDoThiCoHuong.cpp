/* Contributed by: DucNTA */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
int degIn[1005];

void kahn(int n) {
	queue<int> q;
	for(int i = 1; i <= n; ++i) {
		if(degIn[i] == 0) q.push(i);
	}
	int cnt = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		++cnt;
		for(int v : G[u]) {
			degIn[v]--;
			if(degIn[v] == 0) q.push(v);
		}
	}
	if(cnt == n) cout <<"NO\n";
	else cout << "YES\n";
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		rs(G);
		rs(degIn);
		cin >> n >> m;
		while(m--) {
			cin >> x >> y;
			G[x].push_back(y);
			++degIn[y];
		}
		kahn(n);
	}

	return 0;
}


