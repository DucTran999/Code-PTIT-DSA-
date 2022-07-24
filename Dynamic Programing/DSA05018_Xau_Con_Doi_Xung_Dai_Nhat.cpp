#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int sz = s.length();
		s = "x"+s;
		bool F[sz + 1][sz + 1];
		memset(F, 0, sizeof(F));
		for(int i = 1; i <= sz; i++) F[i][i] = 1;
		int ans = 1;
		for(int len = 2; len <= sz; len++) {
			for(int i = 1; i <= sz - len + 1; i++) {
				int j = i + len - 1;
				if(len == 2 && s[i] == s[j])
					F[i][j] = true;
				else {
					F[i][j] = F[i+1][j-1] && (s[i] == s[j]);
				}
				if(F[i][j]) ans = max(ans, len);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

