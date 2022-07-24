#include <bits/stdc++.h>
using namespace std;

int CalcMin(int n, int ins, int del, int copy) {
	if(n == 0)
		return 0;
	if(n == 1) {
		return ins;
	}

	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	dp[1] = ins;
	for(int i = 2; i <=n ; i++) {
		if(i&1) {
			dp[i] = min(dp[i-1] + ins, dp[(i+1)/2] + copy + del);

		} else {
			dp[i] = min(dp[i-1] + ins, dp[i/2] + copy);
		}
	}
	return dp[n];
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n , x, y, z;
		cin >> n >> x >> y >> z;
		cout << CalcMin(n, x, y, z) << endl;
	}
	return 0;
}
