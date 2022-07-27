#include<bits/stdc++.h>
using namespace std;

char checkOp(char op) {
	if(op == '+') return '-';
	else return '+';
}

string transform(string str) {
	
	int len = str.length();
	char* res = new char(len);
	int index = 0, i = 0;
	stack<int> s;
	s.push(0);
	while (i < len) {
		if(str[i] == '(' && i == 0) {
			i++;
			continue;
		}
		if (str[i] == '+') {
			if (s.top() == 1)
				res[index++] = '-';
			if (s.top() == 0)
				res[index++] = '+';

		} else if (str[i] == '-') {
			if (s.top() == 1) {
				if(res[index-1] == '+' || res[index-1] == '-') res[index-1] = '+';
				else res[index++] = '+';
			} else if (s.top() == 0) {
				if(res[index-1] == '+' || res[index-1] == '-') res[index-1] = '-';
				else res[index++] = '-';
			}
		} else if (str[i] == '(' && i > 0) {
			if (str[i - 1] == '-') {
				int x = (s.top() == 1) ? 0 : 1;
				s.push(x);
			} else if (str[i - 1] == '+')
				s.push(s.top());
		} else if (str[i] == ')')
			s.pop();
		else
			res[index++] = str[i];
		i++;
	}
	return res;
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		string eq;
		cin >> eq;
		cout << transform(eq) << endl;
	}

	return 0;
}

