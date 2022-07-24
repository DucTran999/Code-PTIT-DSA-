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
		int dp[n+1];
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			dp[i] = A[i];
			for(int j = 1; j < i; j++) {
				if(A[i] > A[j]) {
					dp[i] = max(dp[i], dp[j] + A[i]);
				}
				ans = max(ans, dp[i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

