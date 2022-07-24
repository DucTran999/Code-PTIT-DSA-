#include<bits/stdc++.h>
using namespace std;

int mc[11][11];
int n, m;

void inp() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> mc[i][j];
		}
	}
}

int findWay(int n, int m) {
	if (n == 1 || m == 1) return 1;
	return findWay(n - 1, m) + findWay(n, m - 1);
}


int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		cout << findWay(n,m) << endl;
	}
	return 0;
}

