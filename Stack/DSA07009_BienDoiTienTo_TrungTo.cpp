#include<bits/stdc++.h>
using namespace std;

string midEq(string eq) {
	stack<string> st;
	for(int i = eq.length() - 1; i >= 0; i--) {
		string subEq = "";
		if(eq[i] == '+' or eq[i] == '-' or eq[i] == '/' or eq[i] == '*') {
			subEq = "(" + st.top() + eq[i];
			st.pop();
			subEq += st.top() + ")";
			st.pop();
			st.push(subEq);
		}else st.push(subEq + eq[i]));
	}
	return st.top();
}

int main() {
	int t = 1;
	cin >> t;
	string eq;
	cin.ignore();
	while(t--) {
		cin >> eq;
		cout << midEq(eq) << endl;
	}
	return 0;
}

