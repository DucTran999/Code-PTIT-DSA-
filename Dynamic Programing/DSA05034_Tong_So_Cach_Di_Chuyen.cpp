#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9+7;

int CountWays(int n, int k) {
	int dp[n+1] = {0};
	dp[0] = 1;
	ll tmp = 0;
	for(int i = 1 ; i<=n; i++) {
		int s = i - k - 1;
		int e = i - 1;
		if(s >= 0) {
			tmp%=M;
			dp[s]%=M;
			tmp-=dp[s];
			tmp%=M;
		}
		if(tmp < 0) tmp +=M;
		tmp += dp[e];
		tmp%=M;
		dp[i] = tmp;
	}
	return dp[n];
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		cout << CountWays(n, k) << endl;
	}
	return 0;
}

