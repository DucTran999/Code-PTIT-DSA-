#include<bits/stdc++.h>
using namespace std;
#define ll long long

int toDigit(char x) {
	return x - '0';
}

long long Calc(string& num) {
	int sz = num.length();
	if(sz == 1) return toDigit(num[0]);
	ll dp[sz];
	dp[0] = toDigit(num[0]);
	ll ans = dp[0];
	for(int i = 1; i < sz; i++) {
		dp[i] = (i+1)*toDigit(num[i]) + 10*(dp[i-1]);
		ans += dp[i];
	}
	return ans;
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		string num;
		cin >> num;
		cout << Calc(num) << endl;
	}
	return 0;
}

