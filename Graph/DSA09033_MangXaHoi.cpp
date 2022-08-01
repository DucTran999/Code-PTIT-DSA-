/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[100005];
bool met[100005];
int trace[10005];

void dfs(int u) {
	met[u] = true;
	for(int v : G[u])
		if(!met[v]) {
			trace[v] = u;
			dfs(v);
		}
}

bool findPath(int s, int e) {
	if(!trace[e]) return false;
	while(s != e) {
		if(!e) return false;
		e = trace[e];
	}
	return true;
}

void allFriend(int n) {
	rs(met);
	rs(trace);
	dfs(1);
	for(int i = 2; i <= n; i++) {
		if(findPath(1, i) == false) {
			cout <<"NO" << endl;
			return;
		}
	}
	cout <<"YES" << endl;
}

int main() {
	sync();
	int t = 1, m, n, x, y;
	cin >> t;
	while(t--) {
		rs(G);
		cin >> n >> m;
		while(m--) {
			cin >> x >> y;
			G[x].push_back(y);
		}
		allFriend(n);
	}

	return 0;
}


