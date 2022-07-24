#include<bits/stdc++.h>
using namespace std;

inline string calc(string s) {
	stack<char> st1, st2;
	s = '+' + s;
	st2.push('+');
	for(char &i : s) {
		if(isalpha(i)) st1.push(i);
		else {
			if(i == '+' or i == '-') {
				if(st2.top() == '+') st1.push(i);
				else st1.push((i == '+') ? '-' : '+');
			}
			if(i == '(') st2.push(st1.top());
			else if(i == ')') st2.pop();
		}
	}
	string res = "";
	while(st1.size() > 1) {
		res = st1.top() + res;
		st1.pop();
	}
	return res;

}

int main() {
	int t = 1;
	cin >> t;
	string s1, s2;
	while(t--) {
		cin >> s1 >> s2;
		cout << ((calc(s1) == calc(s2)) ? "YES" : "NO") << endl;
	}
	return 0;
}
