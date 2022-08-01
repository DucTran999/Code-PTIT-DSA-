/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
bool met[1005], ok;
int m, n;

void dfs(int u, int cnt) {
	if (ok)
		return;
	for (int v : G[u]) {
		if (!met[v]) {
			met[v] = true;
			cnt++;
			if (cnt == n) {
				ok = 1;
				return;
			}
			dfs(v, cnt);
			met[v] = false;
			cnt--;
		}
	}
}

void halfHalminton() {
	for (int i = 1; i <= n; i++) {
		rs(met);
		met[i] = true;
		ok = 0;
		dfs(i, 1);
		if (ok) {
			break;
		}
	}
	cout << ok << endl;
}

int main() {
	sync();
	int t = 1, x, y;
	cin >> t;
	while(t--) {
		rs(G);
		cin >> n >> m;
		while(m--) {
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		halfHalminton();
	}

	return 0;
}


