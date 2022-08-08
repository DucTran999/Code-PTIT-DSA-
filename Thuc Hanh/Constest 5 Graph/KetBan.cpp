/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

bool chuaxet[100005];
vi List[100005];

int DFS(int u) {
	int ans = 1;
	chuaxet[u] = false;
	for(int i = 0; i < List[u].size(); i++)
		if(chuaxet[List[u][i]] == true)
			ans += DFS(List[u][i]);
	return ans;
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		memset(chuaxet, true, sizeof(chuaxet));
		memset(List, 0, sizeof(List));
		cin >> n >> m;
		while(m--) {
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		int res = 0;
		for(int i = 1; i <= n; ++i)
			if(chuaxet[i]) res = max(res, DFS(i));
		cout << res << endl;
	}

	return 0;
}



