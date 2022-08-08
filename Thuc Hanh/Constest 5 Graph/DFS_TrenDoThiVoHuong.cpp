/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi List[1005];
bool met[1005];
int m, n, s;

void inp() {
	rs(List);
	rs(met);
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		List[x].push_back(y);
		List[y].push_back(x);
	}
}

void dfs(int u) {
	met[u] = true;
	cout << u << ' ';
	for(int v : List[u])
		if(!met[v])
			dfs(v);
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		inp();
		dfs(s);
		cout << endl;
	}

	return 0;
}


