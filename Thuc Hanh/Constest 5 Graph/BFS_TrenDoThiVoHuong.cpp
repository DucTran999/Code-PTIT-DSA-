/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

const int maxn = 1005;
vi List[maxn];
bool met[maxn];
int n, m;

void inp() {
	rs(List);
	rs(met);
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		List[x].push_back(y);
		List[y].push_back(x);
	}
}

void bfs(int u) {
	queue<int> q;
	q.push(u);
	met[u] = true;
	while(q.size()) {
		u = q.front();
		cout << u << " ";
		q.pop();
		for(int v : List[u]) {
			if(!met[v]) {
				met[v] = true;
				q.push(v);
			}
		}
	}
	cout << endl;
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		inp();
		bfs(s);
	}

	return 0;
}


