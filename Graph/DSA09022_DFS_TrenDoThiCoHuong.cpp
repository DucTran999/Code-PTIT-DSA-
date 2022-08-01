#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

vi List[1005];
bool met[1005];
int n, m;

void DFS(int u) {
	met[u] = true;
	cout << u << ' ';
	for(int v : List[u])
		if(!met[v])
			DFS(v);
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		int u;
		memset(List, 0, sizeof(List));
		memset(met, 0, sizeof(met));
		cin >> n >> m >> u;
		while(m--) {
			int x, y;
			cin >> x >>y;
			List[x].push_back(y);
		}
		DFS(u);
		cout << endl;
	}

	return 0;
}


