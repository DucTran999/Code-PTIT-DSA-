#include<bits/stdc++.h>
using namespace std;

int main() {
	int L, n;

	cin >> L >> n;
	int dp[n+5][L+5]= {0};
	int W[n+5];
	for(int i = 1; i <= n; i++) {
		cin >> W[i];
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= L; j++) {
			dp[i][j] = dp[i-1][j];
			if(W[i] < j) {
				dp[i][j] = max(dp[i-1][j-W[i]] + W[i], dp[i-1][j]);
			}
		}
	}
	cout << dp[n][L] << endl;

	return 0;
}

