#include<bits/stdc++.h>

using namespace std;

int LCS(string& a, string& b, string& c) {

	int dp[a.size()+5][b.size()+5][c.size()+5];
	memset(dp,0, sizeof(dp));
	for(int i = 1; i <= a.size(); i++) {
		for(int j = 1; j <= b.size(); j++) {
			for(int k = 1; k <= c.size(); k++) {
				if(a[i-1] == b[j-1] and a[i-1] == c[k-1]) {
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				} else {
					dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
				}
			}
		}
	}
	return dp[a.size()][b.size()][c.size()];
}

int main() {
	int t = 1, n, m, k;
	cin >> t;
	string a, b, c;
	while(t--) {
		cin >> n >> m >> k;
		cin >> a >> b >> c;
		int dp[n + 5][m + 5][k + 5];
		cout << LCS(a,b,c) << endl;
	}

	return 0;
}

