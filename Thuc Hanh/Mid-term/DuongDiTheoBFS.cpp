/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
bool met[1005];
int trace[1005];

void bfs(int u){
	queue<int> q;
	q.push(u);
	met[u] = true;
	while(!q.empty()){
		u = q.front(); q.pop();
		for(int &v : G[u]){
			if(!met[v]){
				met[v] = true;
				trace[v] = u;
				q.push(v);
			}
		}
	}
}

void findPath(int s, int e){
	if(!trace[e]){
		cout << "No path" << endl;
		return;
	}
	vi path;
	while(s != e){
		if(!e){
			cout << "No path" << endl;
			return;
		}
		path.push_back(e);
		e = trace[e];
	}
	path.push_back(e);
	reverse(path.begin(), path.end());
	for(int i : path) cout << i << " ";
	cout << endl;
}

int main(){
	sync();
	int t = 1, n, m, s;
	cin >> t;
	while(t--){
		rs(G);
		rs(met);
		rs(trace);
		cin >> n >> m >> s;
		while(m--){
			int x, y;
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		bfs(s);
		for(int i = 1; i <= n;i++){
			if(i!=s) findPath(s,i);
		}
	}
	
	return 0;
}


