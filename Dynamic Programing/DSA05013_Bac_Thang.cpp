#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9+7;

int countWays(int n, int k) {
	ll dp[n+5] = {0};
	dp[0] = 1;
	ll tmp = 0;
	for(int i = 1; i <= n ; i++) {
		ll s = i - k - 1;
		ll e = i - 1;
		if(s >= 0) {
			tmp%=M;
			dp[s]%=M;
			tmp -= dp[s];
			tmp%=M;
		}
		tmp+=dp[e];
		if(tmp < 0) tmp += M;
		dp[i] = tmp%M;
	}

	return dp[n]%M;
}

int main() {
	int t = 1;
	cin >> t;
	int n, k;
	while(t--) {
		cin >> n >> k;
		cout << countWays(n, k) << endl;
	}

	return 0;
}
