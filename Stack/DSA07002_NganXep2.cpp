#include<bits/stdc++.h>
using namespace std;

int main() {
	int q = 0;
	cin >> q;
	string s;
	stack<int> st;
	while(q--) {
		cin >> s;
		if(s == "PUSH") {
			int x = 0;
			cin >> x;
			st.push(x);
		} else if(s == "POP" && !st.empty()) {
			st.pop();
		} else if(s == "PRINT") {
			if(!st.empty()){
			cout << st.top() << endl;
			} else {
				cout << "NONE\n";
			}
		}
	}

	return 0;
}

