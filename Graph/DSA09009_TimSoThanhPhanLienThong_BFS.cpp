#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);


vi List[1005];
bool met[1005];

void bfs(int u) {
	queue<int> q;
	q.push(u);
	met[u] = true;
	while(!q.empty()) {
		u = q.front();
		q.pop();
		for(int v : List[u]) {
			if(!met[v]) {
				met[v] = true;
				q.push(v);
			}
		}
	}
}

int CC(int n){
	memset(met, 0, sizeof(met));
	int tplt = 0;
	for(int i = 1; i <= n; i++){
		if(!met[i]){
			++tplt;
			bfs(i);
		}
	}
	return tplt;
}

int main() {
	sync();
	int t = 1, n, m, x, y;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		memset(List, 0, sizeof(List));
		while(m--) {
			cin >> x >> y;
			List[x].push_back(y);
			List[y].push_back(x);
		}
		cout << CC(n) << endl;
	}

	return 0;
}

