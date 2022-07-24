#include<bits/stdc++.h>
using namespace std;

string equation(string &s) {
	stack<int> st;
	for(char i : s){
		if(i == ')'){
			bool check = 0;
			char cur = st.top();
			st.pop();
			while(cur != '('){
				if(cur == '+' or cur == '-' or cur == '*' or cur == '/')
					check = 1;
				cur = st.top();
				st.pop();
			}
			if(check == 0){
				return "Yes";
			}
		}else st.push(i);
	}
	return "No";
}

int main() {
	int t = 1;
	cin >> t;
	string s;
	cin.ignore();
	while(t--) {
		getline(cin, s);
		cout << equation(s) << endl;
	}
	return 0;
}
