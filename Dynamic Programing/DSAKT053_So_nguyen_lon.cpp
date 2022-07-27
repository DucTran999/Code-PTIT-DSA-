#include<bits/stdc++.h>
using namespace std;

int sameChar(string& a, string& b) {
	a = "x" + a;
	b = "x" + b;
	int dp[a.size()+5][b.size()+5];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= a.size(); i++) {
		for(int  j = 1; j <= b.size(); j++) {
			if(a[i] == b[j]) {
				dp[i][j] = dp[i-1][j-1]+1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[a.size()-1][b.size()-1];
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		string a, b;
		cin >> a >> b;
		cout << sameChar(a, b) << endl;
	}
	return 0;
}

