#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[57];

void fibo() {
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i < 56; i++) {
		dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
	}
}

int main() {
	fibo();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}

