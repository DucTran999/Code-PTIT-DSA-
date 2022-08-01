#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

vi List[1005];
bool visited[1005];

void DFS(int u) {
	visited[u] = true;
	cout << u << ' ';
	for(int v : List[u]) {
		if(!visited[v]) DFS(v);
	}
}

int main() {
	sync();
	int t = 1, n, m, x, y, u;
	cin >> t;
	while(t--) {
		cin >> n >> m >> u;
		memset(List, 0, sizeof(List));
		memset(visited, 0, sizeof(visited));
		while(m--) {
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		DFS(u);
		cout << endl;
	}

	return 0;
}


