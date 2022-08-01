#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi List[1005], lt;
bool met[1005];

bool dfs(int u, int par) {
	met[u] = true;
	for(int v : List[u])
		if(!met[v]) {
			if(dfs(v, u)) return true;
		} else if(v != par) return true;
	return false;
}

void CC(int n) {
	for(int i = 1; i<=n; i++) {
		if(!met[i]) {
			if(dfs(i,0)) {
				cout <<"YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		rs(List);
		rs(met);
		while(m--) {
			cin >> x >>y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		CC(n);
	}

	return 0;
}


