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

void dfs(int u) {
	met[u] = true;
	for(int v : List[u])
		if(!met[v]) {
			trace[v] = u;
			dfs(v);
		}

}

bool findPath(int s, int e) {
	if(!trace[e]) {
		return false;
	}
	while(s != e) {
		if(!e) {
			return false;
		}
		e = trace[e];
	}
	return true;
}

int main() {
	sync();
	int n, m, x, y, ok = 0;
	rs(List);
	rs(met);
	rs(trace);
	cin >> n >> m;
	while(m--) {
		int x, y;
		cin >> x >> y;
		List[x].push_back(y);
		List[y].push_back(x);
	}
	dfs(1);
	for(int i = 2; i<=n; i++) {
		if(!findPath(1, i)) {
			ok = 1;
			cout << i << endl;
		}
	}
	if(ok == 0) cout << 0 << endl;

	return 0;
}


