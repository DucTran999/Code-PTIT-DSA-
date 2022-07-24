#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> st;
	while(n > 0) {
		st.push(n&1);
		n>>=1;
	}
	while(!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}

