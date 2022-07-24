#include<bits/stdc++.h>
using namespace std;

int calc(char op, int a, int b){
	if(op == '+') return a + b;
	if(op == '-') return a - b;
	if(op == '*') return a * b;
	if(op == '/') return a / b;
} 

int calcPostfix(string eq){
	stack<int> st;
	for(int i = 0; i < eq.length();i++){
		if(isdigit(eq[i])){
			st.push(eq[i]-'0');
		}else{
			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();
			int res = calc(eq[i], a, b);
			st.push(res);
		}
	} 
	return st.top();
}
int main(){
	int t = 1;
	cin >> t;
	while(t--){
		string eq;
		cin >> eq;
		cout << calcPostfix(eq) << endl;
	}
	return 0;
}

