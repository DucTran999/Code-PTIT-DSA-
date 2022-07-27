#include<bits/stdc++.h>
using namespace std;

int Calc(string &s) {
	int n = s.length();
	s= "x"+s;
	bool dp[n+1][n+1];
	memset(dp, false, sizeof(dp));
	int ans = 1;
	for(int i = 1; i<=n; i++) dp[i][i] = true;
	for(int len = 2; len <= n; len++) {
		for(int i = 1; i <= n - len + 1; i++) {
			int j = i + len - 1;
			if(len == 2 && s[i] == s[j]) dp[i][j] = true;
			else
				dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
			if(dp[i][j]) ans = max (ans, len);
		}
	}
	return ans;
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

