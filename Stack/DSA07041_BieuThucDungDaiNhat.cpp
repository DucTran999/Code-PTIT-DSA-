#include<bits/stdc++.h>
using namespace std;

int calc(string s) {
	stack<int> st;
	int cnt =0;
	for(char i : s) {
		if(i == '(') st.push(i);
		else {
			if(st.size() and st.top() == '(') {
				cnt+=2;
				st.pop();
			} else st.push(i);
		}
	}
	return cnt;
}

int main() {
	int t = 1;
	cin >> t;
	cin.ignore();
	while(t--) {
		string s;
		cin >> s;
		cout << calc(s) << endl;
	}
	return 0;
}

