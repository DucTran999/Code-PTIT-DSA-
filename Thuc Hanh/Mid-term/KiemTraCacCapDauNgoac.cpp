/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

void check(string& s) {
	stack<char> st;
	for(char &i : s) {
		if(i == '[' or i == '(' or i == '{')
			st.push(i);
		else if(!st.empty() and i == ')') {
			if(st.top() == '(') {
				st.pop();
			} else {
				cout << "false" << endl;
				return;
			}
		} else if(!st.empty() and i == '}') {
			if(st.top() == '{') {
				st.pop();
			} else {
				cout << "false" << endl;
				return;
			}
		} else if(!st.empty() and i == ']') {
			if(st.top() == '[') {
				st.pop();
			} else {
				cout << "false" << endl;
				return;
			}
		} else if(st.empty() and (i == ')' or i == '}' or i== ']')) {
			cout << "false" << endl;
			return;
		}
	}
	if(st.empty())
	cout << "true" << endl;
	else cout << "false" << endl;
}

int main() {
	sync();
	int t = 1;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		check(s);
	}

	return 0;
}


