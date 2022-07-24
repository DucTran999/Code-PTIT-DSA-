#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int A[n+1];
		for(int i = 1; i <= n; i++) {
			cin >> A[i];
		}

		if(n == 1) {
			cout << A[1] << endl;
		} else if(n == 2) {
			cout << max(A[1],A[2]) << endl;
		} else {
			int dp[n+5];
			memset(dp, 0, sizeof(dp));
			dp[1] = A[1];
			dp[2] = max(A[1],A[2]);
			for(int i = 3; i <= n; i++) {
				dp[i] = max(dp[i-1], dp[i-2] + A[i]);
			}
			cout << dp[n] << endl;
		}
	}
	return 0;
}

