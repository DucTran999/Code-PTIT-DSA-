/* Contributed by Anh Duc*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
bool met[1005];

void dfs(int u) {
	met[u] = true;
	for(int v : G[u])
		if(!met[v])
			dfs(v);
}

void cutVertex(int n) {
	rs(met);
	int tplt = 0;
	for(int i = 1; i <= n; i++) {
		if(!met[i]) {
			++tplt;
			dfs(i);
		}
	}
	int cnt  = 0;
	for(int i = 1; i <= n ; i++) {
		rs(met);
		cnt = 0;
		met[i] = true;
		for(int j = 1; j <= n; j++) {
			if(!met[j]) {
				cnt++;
				dfs(j);
			}
		}
		if(cnt > tplt) cout << i << " ";
	}
	cout << endl;
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		rs(G);
		cin >> n >> m;
		while(m--) {
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		cutVertex(n);
	}
	
	return 0;
}



