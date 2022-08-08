#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

vi List[100005], rList[100005];
bool used[100005];
int n, m;
stack<int> st;

void inp() {
	cin >> n >> m;
	memset(List, 0, sizeof(List));
	memset(rList, 0, sizeof(rList));
	while(st.size()) st.pop();
	for(int i = 1; i <=m; i++) {
		int x, y;
		cin >> x >> y;
		List[x].push_back(y);
		rList[y].push_back(x);
	}
}

void DFS1(int u) {
	used[u] = true;
	for(int &v : List[u])
		if(!used[v])
			DFS1(v);
	st.push(u);
}

void DFS2(int u) {
	used[u] = true;
	for(int &v : rList[u])
		if(!used[v])
			DFS2(v);
}

void SCC() {
	memset(used, 0, sizeof(used));
	for(int i = 1 ; i <= n; i++) {
		if(!used[i])
			DFS1(i);
	}

	memset(used, 0, sizeof(used));
	int cnt = 0;
	while(!st.empty()) {
		int u = st.top();
		st.pop();
		if(!used[u]) {
			cnt++;
			DFS2(u);
		}
	}
	cout << cnt << endl;
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		inp();
		SCC();
	}

	return 0;
}



