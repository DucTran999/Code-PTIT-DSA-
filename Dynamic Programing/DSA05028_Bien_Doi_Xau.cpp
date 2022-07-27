#include<bits/stdc++.h>
using namespace std;
#define ll long long

int Calc(string &s1, string&s2) {
	s1 = "x" + s1;
	s2 = "x" + s2;
	int dp[s1.size()+5][s2.size()+5];
	for(int i = 0; i < s1.size(); i++) {
		dp[i][0] = i;
	}
	for(int i = 0; i < s2.size(); i++) {
		dp[0][i] = i;
	}
	for(int i = 1; i < s1.size(); i++) {
		for(int j = 1; j < s2.size(); j++) {
			if(s1[i] == s2[j]) {
				dp[i][j]=dp[i-1][j-1];
			} else {
				dp[i][j] = min ({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
			}
		}
	}
	return dp[s1.size()-1][s2.size()-1];
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		string s1, s2;
		cin >> s1 >> s2;
		cout << Calc(s1, s2) << endl;
	}
	return 0;
}

