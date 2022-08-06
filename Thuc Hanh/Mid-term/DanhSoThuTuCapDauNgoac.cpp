/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

void check(string& s){
	stack<int> st;
	int idx = 0;
	for(char &i : s){
		if(i == '('){
			idx++;
			st.push(idx);
			cout << idx << " ";
		} 
		else if(i == ')'){
			cout << st.top() << " ";
			st.pop();
		}
	}
	cout << endl;
}

int main(){
	sync();
	int t = 1;
	string s;
	cin >> t;
	cin.ignore();
	while(t--){
		getline(cin, s);
		check(s);
	}
	
	return 0;
}


