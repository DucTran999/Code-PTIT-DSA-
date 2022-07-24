#include<bits/stdc++.h>
using namespace std;

string prefix(string pFix) {
	stack<string> st;
	for(char i : pFix){
		if(isalpha(i)){
			st.push(string(1,i));
		}else{
			string tmp="";
			tmp += st.top(); st.pop();
			tmp = st.top() + tmp; st.pop();
			tmp = i + tmp;
			st.push(tmp);
		}
	}
	return st.top();
}

int main() {
	int t = 1;
	cin >> t;
	cin.ignore();
	string postfix;
	while(t--) {
		cin >> postfix;
		cout << prefix(postfix) << endl;
	}
	return 0;
}

