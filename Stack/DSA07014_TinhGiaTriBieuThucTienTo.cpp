#include<bits/stdc++.h>
using namespace std;

int calc(char op, int a, int b){
	if(op == '+') return a + b;
	if(op == '-') return a - b;
	if(op == '*') return a * b;
	if(op == '/') return a / b;
} 

int calcPrefix(string eq){
	stack<int> st;
	for(int i = eq.length()-1; i > -1; i--){
		if(isdigit(eq[i])){
			st.push(eq[i]-'0');
		}else{
			int a = st.top();
			st.pop();
			int b = st.top();
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
		cout << calcPrefix(eq) << endl;
	}
	return 0;
}

