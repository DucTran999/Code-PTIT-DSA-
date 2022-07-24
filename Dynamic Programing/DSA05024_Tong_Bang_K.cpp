#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9+7;

int A[1005], dp[1005], n, k;

void inp() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
	}
}

ll Calc() {
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= n; j++) {
			if(A[j] <= i) {
				dp[i] = (dp[i] + dp[i-A[j]])%M;
			}
		}
	}
	return dp[k];
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		inp();
		cout << Calc()<< endl;
	}
	return 0;
}
