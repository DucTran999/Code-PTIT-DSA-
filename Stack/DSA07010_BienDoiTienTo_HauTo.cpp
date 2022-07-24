#include<bits/stdc++.h>
using namespace std;

string suffix(string eq) {
	stack<string> st;
	for(int i = eq.length() - 1; i >= 0; i--) {
		string suf = "";
		if(eq[i] == '+' or eq[i] == '*' or eq[i] == '/' or eq[i] == '-') {
			suf+=st.top();
			st.pop();
			suf+= st.top() + eq[i];
			st.pop();
			st.push(suf);
		} else st.push(suf + eq[i]);
	}
	return st.top();
}
int main() {
	int t = 1;
	cin >> t;
	cin.ignore();
	string eq;
	while(t--) {
		cin >> eq;
		cout << suffix(eq) << endl;
	}
	return 0;
}

