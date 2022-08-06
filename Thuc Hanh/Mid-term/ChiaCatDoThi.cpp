/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
bool met[1005];
int tplt = 0;

void dfs(int u) {
	met[u] =true;
	for(int v : G[u]) {
		if(!met[v])
			dfs(v);
	}
}

void countTPLT(int n) {
	rs(met);
	for(int i= 1; i<=n; i++) {
		if(!met[i]) {
			tplt++;
			dfs(i);
		}
	}
}

int countCutVertex(int n) {
	int ans = 0;
	int vertex = 0;
	for(int i = 1; i<=n; i++) {
		rs(met);
		int cnt = 0;
		met[i] = true;
		for(int i = 1; i<=n; i++) {
			if(!met[i]) {
				cnt++;
				dfs(i);
			}
		}
		if(tplt < cnt) {
			if(cnt > ans) {
				ans = max(ans, cnt);
				vertex = i;
			}
		}
	}
	return vertex;
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		rs(G);
		tplt = 0;
		cin >> n >> m;
		while(m--) {
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		countTPLT(n);
		cout << countCutVertex(n) << endl;
	}

	return 0;
}


