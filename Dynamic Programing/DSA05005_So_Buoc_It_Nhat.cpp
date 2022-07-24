#include<bits/stdc++.h>
using namespace std;

int main() {

	int t = 1;
	cin >> t;
	int n;
	while(t--) {

		cin >> n;
		int A[n+1];
		int dp[n+1];
		memset(dp, 0, sizeof(dp));

		for(int i = 1; i <= n; i++) {
			cin >> A[i];
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			dp[i] = 1;
			for(int j = 1; j < i; j++) {
				if(A[j] <= A[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		cout << n - ans << endl;
	}

	return 0;
}

