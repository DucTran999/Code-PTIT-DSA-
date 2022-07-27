#include<bits/stdc++.h>
using namespace std;
long long A[1005][1005], dp[1005][1005], m, n;

long long Calc() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = A[0][0];
	for(int i = 1; i < m ; i++)	dp[i][0] = A[i][0] + dp[i-1][0];
	for(int i = 1; i < n ; i++)	dp[0][i] = dp[0][i-1] + A[0][i];

	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + A[i][j];
		}
	}

	return dp[m-1][n-1];
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		cin >> m >> n;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				cin >> A[i][j];
			}
		}
		cout << Calc() << endl;
	}
	return 0;
}

