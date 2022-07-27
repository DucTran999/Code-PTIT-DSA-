#include<bits/stdc++.h>
using namespace std;

int precedence(char op) {
	if(op == '^')
		return 3;
	else if(op == '*' or op == '/')
		return 2;
	else if(op == '+' or op == '-')
		return 1;
	return -1;
}

string postfix(string infix) {
	string post ="";
	stack<char> st;
	for(char i : infix) {
		if(isalpha(i)) {
			post+=i;
		} else if(i == '(') {
			st.push(i);
		} else if(i == ')') {
			while(!st.empty() and st.top() != '(') {
				post+=st.top();
				st.pop();
			}
			st.pop();
		} else if(i == '+' or i == '-' or i == '*' or i == '/' or i == '^') {
			while(!st.empty() and precedence(st.top()) >= precedence(i)) {
				post+=st.top();
				st.pop();
			}
			st.push(i);
		}
	}
	if(!st.empty() and st.top()!='(') {
		post+=st.top();
	}
	return post;
}

int main() {
	int t = 1;
	cin >> t;
	string infix;
	cin.ignore();
	while(t--) {
		cin >> infix;
		cout << postfix(infix) << endl;
	}

	return 0;
}

