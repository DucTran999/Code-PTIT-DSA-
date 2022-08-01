/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

vi List[1005];
bool visited[1005];

void BFS(int u) {
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()) {
		u = q.front();
		cout << u << ' ';
		q.pop();
		for(int v : List[u]) {
			if(!visited[v]) {
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

int main() {
	sync();
	int t = 1, m, n, u, x, y;
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
		BFS(u);
		cout << endl;
	}

	return 0;
}


