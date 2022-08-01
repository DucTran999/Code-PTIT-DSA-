#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int A[n+1];
	int dp[n+1];
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	int ans = INT_MIN;
	for(int i = 1; i <=n; i++) {
		dp[i] = 1;
		for(int j = 1; j < i; j++) {
			if(A[j] < A[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			ans = max(ans, dp[i]);
		}
	}
	cout << ans << endl;
	return 0;
}

