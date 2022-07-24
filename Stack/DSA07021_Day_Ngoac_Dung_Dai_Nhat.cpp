#include<bits/stdc++.h>
using namespace std;
int calc(string s){
	stack<int> st;
	int res = 0;
	st.push(-1);
	for(int i = 0; i < s.length(); i++){
		if(s[i] == ')'){
			st.pop();
			if(!st.empty()){
				int tmp = st.top();
				res = max(res, i - tmp);
			}else{
				st.push(i);
			}
		}else{
			st.push(i);
		}
	}
	return res;
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
