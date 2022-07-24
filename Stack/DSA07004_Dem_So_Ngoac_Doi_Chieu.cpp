#include<bits/stdc++.h>
using namespace std;

int calc(string &s) {
	stack<int> st;
	for(char i : s){
		if(i == ')' and !st.empty()){
			if(st.top() == '('){
				st.pop();
			}else{
				st.push(i);
			}
		}else st.push(i);
	}
	int remain = st.size();
	int cnt = 0;
	while(!st.empty()){
		if(st.top() == ')'){
			cnt++;
		}
		st.pop();
	}
	return remain/2 + cnt%2;
}

int main() {
	int t = 1;
	cin >> t;
	string s;
	while(t--) {
		cin >> s;
		cout << calc(s) << endl;
	}
	return 0;
}
