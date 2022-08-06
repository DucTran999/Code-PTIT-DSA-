/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

void check(string& s){
	int cnt = 0;
	int maxl = 0;
	stack<char> st;
	for(char i : s){
		if(i == '(') st.push(i);
		else if(i == '['){
			if(st.empty()){
				maxl = max(maxl, cnt);
				cnt = 0;
				st.push(i);
			}else st.push(i);
		}
		else if(!st.empty() and i == ')'){
			if(st.top() == '(') st.pop();
			else {
				cout << cnt << endl;
				return;
			}
		}else if(!st.empty() and i == ']'){
			if(st.top() == '['){
				st.pop();
				cnt++;
			}
			maxl = max(maxl, cnt);
		}
	}
	cout << maxl << endl;
}

int main(){
	sync();
	string s;
	getline(cin, s);
	check(s);
	
	return 0;
}


