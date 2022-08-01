#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

const int maxn = 1e5+5;

vi G[maxn], rG[maxn];
bool met[maxn];
stack<int> st;

void dfs(int u) {
	met[u] = true;
	for(int v : G[u])
		if(!met[v])
			dfs(v);
	st.push(u);
}

void dfs2(int u) {
	met[u] = true;
	for(int v : rG[u])
		if(!met[v])
			dfs(v);
}

void kosaraju(int n) {
	rs(met);
	for(int i = 1; i <= n; i++) {
		if(!met[i]) {
			dfs(i);
		}
	}

	int tplt = 0;
	rs(met);
	while(!st.empty()) {
		int u = st.top();
		st.pop();
		if(!met[u]) {
			tplt++;
			dfs2(u);
		}
	}
	if(tplt == 1) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		rs(G);
		rs(rG);
		cin >> n >> m;
		while(m--) {
			cin >> x >> y;
			G[x].push_back(y);
			rG[y].push_back(x);
		}
		kosaraju(n);
	}

	return 0;
}



