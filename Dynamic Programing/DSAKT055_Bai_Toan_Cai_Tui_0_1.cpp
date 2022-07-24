#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n, L;
		cin >> n >> L;
		int W[n+5];
		int V[n+5];
		for(int i = 1; i <= n; i++) cin >> W[i];
		for(int i = 1; i <= n; i++) cin >> V[i];
		int dp[n+5][L+5];
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= L; j++) {
				if(W[i] <= j) {
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
				} else {
					dp[i][j] = dp[i-1][j];
				}
				ans = max(dp[i][j], ans);
			}
		}
		cout << ans << endl;
	}

	return 0;
}

