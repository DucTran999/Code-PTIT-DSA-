#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check(string &s) {
	if(s[0] == '0' || s[s.length() - 1] == '0') {
		return false;
	}
	for(int i = 0; i < s.length() - 1; i++) {
		if(s[i] == '0' && s[i+1] == '0')
			return false;
	}
	return true;
}

int Calc(string &s) {
	int sz = s.length();
	int dp[1005] = {0};
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= sz; ++i) {
		if(s[i - 1] > '0')
			dp[i] = dp[i - 1];
		if(s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7'))
			dp[i] += dp[i - 2];
	}
	return dp[sz];
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		if(!check(s)) {
			cout << 0 << endl;
		} else {
			cout << Calc(s) << endl;
		}
	}
	return 0;
}

