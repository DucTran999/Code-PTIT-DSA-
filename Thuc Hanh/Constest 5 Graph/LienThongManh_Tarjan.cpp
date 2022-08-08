/* Contributed by Anh Duc*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vi G[1005];
int Low[1005], Num[1005];
int cnt, n, m, tplt;
stack<int> st;

void tarjan(int u) {
	Low[u] = Num[u] = ++cnt;
	st.push(u);
	for(int v : G[u]) {
		if(!Num[v]) {
			tarjan(v);
			Low[u] = min(Low[u], Low[v]);
		} else Low[u] = min(Low[u], Num[v]);
	}
	if(Num[u] == Low[u]) {
		++tplt;
		int tmp;
		do {
			tmp = st.top();
			st.pop();
			Num[tmp] = Low[tmp] = INT_MAX;
		} while(tmp != u);
	}
}

int main() {
	sync();
	rs(G);
	cnt = tplt = 0;
	cin >> n >> m;
	while(m--) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
	}
	for(int i = 1; i <= n ; i++)
		if(!Num[i])
			tarjan(i);
	cout << tplt << endl;

	return 0;
}

