#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

vi List[1005];
bool visited[1005];
int m, n;

void inp() {
	memset(List, 0, sizeof(List));
	cin >> n >> m;
	while(m--) {
		int x, y;
		cin >> x >>y;
		List[x].push_back(y);
		List[y].push_back(x);
	}
}

void DFS(int u) {
	visited[u] = true;
	for(int &v : List[u])
		if(!visited[v]) DFS(v);
}

void cutVertices() {
	int tplt = 0;
	memset(visited, false, sizeof(visited));
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			++tplt;
			DFS(i);
		}
	}

	for(int i = 1; i <= n ; i++) {
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		int cnt = 0;
		for(int j = 1; j <= n; j ++) {
			if(!visited[j]) {
				++cnt;
				DFS(j);
			}
		}
		if(cnt > tplt) cout << i << " ";
	}
	cout << endl;
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		inp();
		cutVertices();
	}

	return 0;
}


