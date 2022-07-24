#include<bits/stdc++.h>
using namespace std;

int Calc(int *A, int n) {
	if (n == 1) return A[1];
	if(n == 2) return max(A[1], A[2]);
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	dp[1] = A[1];
	dp[2] = max(A[1], A[2]);
	for(int i = 3; i <= n ; i++) {
		dp[i] = max(dp[i-1], dp[i-2] + A[i]);
	}
	return dp[n];
}

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
		cout << Calc(A,n) << endl;
	}

	return 0;
}

