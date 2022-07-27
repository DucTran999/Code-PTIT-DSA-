#include<bits/stdc++.h>
using namespace std;

int Calc(string& s) {
	int n = s.length();
	s = "x"+s;
	int dp[n+5][n+5];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; i++)
		dp[i][i] = 1;
	for(int len = 2; len <= n; len++) {
		for(int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			if(len == 2 && s[i] == s[j]) dp[i][j]= 2;
			else if(s[i] == s[j]) {
				dp[i][j]= dp[i+1][j-1] + 2;
			} else {
				dp[i][j] = max (dp[i][j-1], dp[i+1][j]);
			}
		}
	}
	return n - dp[1][n];
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << Calc(s) << endl;
	}
	return 0;
}

