#include<bits/stdc++.h>
using namespace std;

string check(string s) {
	stack<int> st;
	for(char i : s) {
		if(i == '[' or i == '{' or i == '(') {
			st.push(i);
		} else {
			if(i == '}' and st.size()) {
				if(st.top() == '{')
					st.pop();
				else return "NO";
			} else if(i == ')' and st.size()) {
				if(st.top() == '(')
					st.pop();
				else return "NO";
			} else if(i == ']' and st.size()) {
				if(st.top() == '[')
					st.pop();
				else return "NO";
			}
		}
	}
	return "YES";
}

int main() {
	int t = 1;
	cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		cin >> s;
		cout << check(s) << endl;
	}

	return 0;
}

