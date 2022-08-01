#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		int dp[41][41] = {};
		string tmp = s;
		reverse(tmp.begin(), tmp.end());
		for(int i = 0; i < s.size(); ++i) {
			for(int j = 0; j < tmp.size(); ++j) {
				if(s[i] == tmp[j])
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else
					dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
		int M = dp[s.size()][tmp.size()];
		cout << s.size() - M << endl;
	}
	return 0;
}
