#include<bits/stdc++.h>
using namespace std;

void reverseSen(string s) {
	s+=" ";
	stack<string> st;
	int l, r;
	l = r = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] != ' ') {
			r++;
		} else {
			string tmp = "";
			for(int j = l; j < r; j++) {
				tmp+=s[j];
			}
			st.push(tmp);
			r+=1;
			l = r;
		}
	}
	while(!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

int main() {
	int t = 1;
	cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		getline(cin, s);
		reverseSen(s);
	}
	return 0;
}

