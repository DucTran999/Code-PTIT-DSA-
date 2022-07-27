#include<bits/stdc++.h>
using namespace std;
int A[505][505], dp[505][505], m, n;

int Calc() {
	int ans = 0;
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i < n; i++) dp[0][i] = A[0][i];
	for(int i = 0; i < m; i++) dp[i][0] = A[i][0];


	for(int i = 1; i < m; i++) {
		for(int j = 1; j < n; j++) {
			if(A[i][j] == 1) {
				dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
			}
			ans = max(ans , dp[i][j]);
		}
	}
	return ans;
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

