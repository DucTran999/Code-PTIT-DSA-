#include<bits/stdc++.h>
using namespace std;

string infix(string p) {
	stack<string> st;
	for(char i : p) {
		if(isalpha(i)) st.push(string(1,i));
		else {
			string tmp = st.top();
			st.pop();
			tmp = '(' + st.top() + i + tmp + ')';
			st.pop();
			st.push(tmp);
		}
	}
	return st.top();
}

int main() {
	int t = 1;
	cin >> t;
	cin.ignore();
	while(t--) {
		string postfix;
		cin >> postfix;
		cout << infix(postfix) << endl;
	}
	return 0;
}

