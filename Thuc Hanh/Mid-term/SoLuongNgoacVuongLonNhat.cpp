/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

void check(string& s) {
	stack <pair<char,int>> st;
	int ans=0, cnt=0;
	st.push({'$',0});
	for(char i : s) {
		if(st.size() and i == ')' and st.top().first == '(' or i == ']' and st.top().first == '[') {
			st.pop();
			if(st.size()) {
				ans = max(ans, cnt - st.top().second);
			}
		} else {
			cnt += i == '[';
			st.push({i,cnt});
		}
	}
	cout<< ans <<endl;
}

int main() {
	sync();
	string s;
	getline(cin, s);
	check(s);

	return 0;
}


