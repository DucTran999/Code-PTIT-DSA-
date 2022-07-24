#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t = 1;
	cin >> t;
	string a, b;
	while(t--) {
		cin >> a >> b;
		int dp[a.size()+1][b.size()+1];
		memset(dp,0, sizeof(dp));
		for(int i = 0; i < a.size(); i++) {
			for(int j = 0; j < b.size(); j++) {
				if(a[i] == b[j]) {
					dp[i+1][j+1] = dp[i][j] + 1;
				} else {
					dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
				}
			}
		}
		cout << dp[a.size()][b.size()] << endl;
	}
	return 0;
}

