#include<bits/stdc++.h>
using namespace std;

unsigned long long int dp[105];

void catalan() {
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= 100; i++) {
		for(int j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}
}

int main() {
	catalan();
	int t = 1;
	cin >> t;
	int n;
	while(t--) {
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}

