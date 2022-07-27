#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

string infix(string s) {
	stack<string> st;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			string a = st.top();
			st.pop();
			string b = st.top();
			st.pop();
			string tmp = b + s[i] + a;
			st.push(tmp);
		} else {
			st.push(string(1,s[i]));
		}
	}
	return st.top();
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		cout << infix(s) << endl;
	}

	return 0;
}


