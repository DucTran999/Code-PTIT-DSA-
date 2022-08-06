/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int calc(string& s) {
	int n = s.length();
	int dp[n];
	for(int i = 0; i < n; i++) dp[i] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(s[i] >= s[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	int maxL = dp[0];
	for(int i = 1; i < n; i++) {
		if(dp[i] > maxL) {
			maxL = dp[i];
		}
	}
	return maxL;
}

int main() {
	sync();
	int t = 1;
	string s;
//	cin >> t;
	while(t--) {
		cin >> s;
		cout << calc(s) << endl;
	}

	return 0;
}


