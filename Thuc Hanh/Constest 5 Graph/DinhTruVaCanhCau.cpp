#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
int Num[1005], Low[1005] , cnt, brigde;
bool cutVerties[1005];

void tarjan(int u, int p) {
	Low[u] = Num[u] = ++cnt;
	int child = 0;
	for(int v : G[u]) {
		if(v != p) {
			if(!Num[v]) {
				tarjan(v, u);
				child++;
				Low[u] = min(Low[u], Low[v]);

				if(Low[v] >= Num[v]) {
					brigde++;
				}
				if(u == p) {
					if(child >= 2) {
						cutVerties[u] = true;
					}
				} else {
					if(Low[v] >= Num[u]) {
						cutVerties[u] = true;
					}
				}
			} else Low[u] = min(Low[u], Num[v]);
		}
	}

}

void countBridgeAndCV(int n) {
	for(int i = 1; i<=n; i++)
		if(!Num[i])
			tarjan(i, i);
	int vertex = 0;
	for(int i = 1; i <= n; i++)
		if(cutVerties[i]) vertex++;
	cout << vertex  << " " << brigde << " ";
}

int main() {
	sync();
	int n, m;
	cin >> n >> m;
	rs(G);
	rs(Num);
	rs(Low);
	rs(cutVerties);
	brigde = cnt = 0;
	while(m--) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
	}
	countBridgeAndCV(n);

	return 0;
}


