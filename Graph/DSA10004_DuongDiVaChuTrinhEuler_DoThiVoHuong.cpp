/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

int n, m;
vi List[1005];
int degree[1005];

void inp() {
	memset(List, 0, sizeof(List));
	memset(degree, 0, sizeof(degree));
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		List[x].push_back(y);
		List[y].push_back(x);
		degree[x]++;
		degree[y]++;
	}
}

bool checkEulerCycle() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(degree[i] & 1)
			return false;
	}
	return true;
}

bool checkEulerPath() {
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(degree[i] & 1)
			cnt++;
	if(cnt == 0 or cnt == 2)
		return true;

	return false;
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		inp();
		bool EC = checkEulerCycle();
		bool EP = checkEulerPath();
		if(EC) cout << 2;
		else if(EP) cout << 1;
		else cout << 0;
		cout << endl;
	}

	return 0;
}



