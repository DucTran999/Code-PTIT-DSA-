/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
bool met[1005];
int tplt = 0;
vector<pair<int, int>> edge;

void dfs(int u){
	met[u] =true;
	for(int v : G[u]){
		if(!met[v])
			dfs(v);
	}
}

void countTPLT(int n){
	rs(met);
	for(int i= 1; i<=n;i++){
		if(!met[i]){
			tplt++;
			dfs(i);
		}
	}
}

int countCutVertex(int n){
	int ans = 0;
	for(int i = 1; i<=n;i++){
		rs(met);
		int cnt = 0;
		met[i] = true;
		for(int i = 1; i<=n;i++){
			if(!met[i]){
				cnt++;
				dfs(i);
			}
		}
		if(tplt < cnt) ans++;
	}
	return ans;
}

void dfs2(int u, int x, int y){
	met[u] = true;
	for(int &v : G[u]){
		if((v ==x and u == y) or (v==y and u ==x))continue;
		if(!met[v])
			dfs2(v,x,y);
	}
}

int countBridge(int n){
	int ans = 0;
	for(auto e : edge){
		int x = e.first;
		int y = e.second;
		rs(met);
		int cnt = 0;
		for(int i = 1; i <= n ; i++){
			if(!met[i]){
				cnt++;
				dfs2(i,x,y);
			}
		}
		if(cnt > tplt) ans++;
	}	
	return ans;
} 

int main(){
	sync();
	int t = 1, n, m, x, y;
//	cin >> t;
	while(t--){
		rs(G);
		tplt = 0;
		cin >> n >> m;
		while(m--){
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
			edge.push_back({x,y});
		}
		countTPLT(n);
		cout << countCutVertex(n) << " " << countBridge(n) << endl;
	}
	
	return 0;
}


