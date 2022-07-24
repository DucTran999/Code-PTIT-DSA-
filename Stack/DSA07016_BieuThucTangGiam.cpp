#include<bits/stdc++.h>
using namespace std;

string solve(string s) {
	stack<int> st;
	string ans = "";
	for(int i = 0; i <= s.length(); i++) {
		st.push(i + 1);
		if(i == s.length() or s[i] == 'I') {
			while(!st.empty()) {
				ans += to_string(st.top());
				st.pop();
			}
		}
	}
	return ans;
}
int main() {
	int t = 1;
	cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		cin >> s;
		cout << solve(s) << endl;
	}
	return 0;
}

