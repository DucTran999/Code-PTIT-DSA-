#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[10005], n;
ll Calc() {
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++) {
		dp[i] = i;
		for(int j = 1; j <= sqrt(i); j++) {
			dp[i] = min(dp[i], dp[i-j*j] + 1);
		}
	}
	return dp[n];
}

int main() {
	Calc();
	int t = 1;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << Calc() << endl;
	}
	return 0;
}
