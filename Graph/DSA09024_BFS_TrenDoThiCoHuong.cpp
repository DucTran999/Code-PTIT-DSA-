#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

vi List[1005];
bool met[1005];

void BFS(int u) {
	queue<int> q;
	q.push(u);
	met[u] = true;
	while(!q.empty()) {
		u = q.front();
		cout << u << ' ';
		q.pop();
		for(int &v : List[u]) {
			if(!met[v]) {
				met[v] = true;
				q.push(v);
			}
		}
	}
}

int main() {
	sync();
	int t = 1, n, m, x, y, u;
	cin >> t;
	while(t--) {
		memset(List, 0, sizeof(List));
		memset(met, 0 , sizeof(met));
		cin >> n >> m >> u;
		while(m--) {
			cin >> x >> y;
			List[x].push_back(y);
		}
		BFS(u);
		cout << endl;
	}

	return 0;
}


