/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[100005];
bool met[100005];

int dfs(int u) {
	int ans = 1;
	met[u] =  true;
	for(int i = 0; i < G[u].size(); i++)
		if(!met[G[u][i]]) ans += dfs(G[u][i]);
	return ans;
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		rs(G);
		rs(met);
		cin >> n >> m;
		while(m--) {
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}

		int res = 0;
		for(int i = 1; i <= n; i++) {
			if(!met[i])
				res = max(res, dfs(i));
		}
		cout << res << endl;
	}

	return 0;
}


