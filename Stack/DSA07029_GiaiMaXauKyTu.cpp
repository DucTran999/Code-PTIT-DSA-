#include<bits/stdc++.h>
using namespace std;

string decrypt(string cText) {
	stack<char> st;
	for(char i : cText) {
		if(i == ']') {
			string tmp ="";
			while(!st.empty() and st.top() != '[') {
				tmp = st.top() + tmp;
				st.pop();
			}
			st.pop();
			if(st.size() and isdigit(st.top())) {
				string loop ="";
				while (!st.empty() && isdigit(st.top())) {
					loop = st.top() + loop;
					st.pop();
				}
				int number = stoi(loop);
				string repeat ="";
				while(number--)
					repeat += tmp;
				for (char c : repeat)
					st.push(c);
			} else {
				for (char c : tmp)
					st.push(c);
			}
		} else st.push(i);
	}

	string pText = "";
	while (!st.empty()) {
		pText = st.top() + pText;
		st.pop();
	}
	return pText;
}

int main() {
	int t = 1;
	cin >> t;
	cin.ignore();
	while(t--) {
		string cText;
		cin >> cText;
		cout << decrypt(cText) << endl;
	}
	return 0;
}

