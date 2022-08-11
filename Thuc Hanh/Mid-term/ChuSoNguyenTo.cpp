/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

void genAll(int n) {
	queue<string> q;
	q.push("2"); q.push("3"); q.push("5"); q.push("7");
	while(q.front().size() <= n) {
		string s = q.front();
		q.pop();
		if(s.size() > 3 and s[s.size()-1] != '2') {
			set<char> setA;
			for(char c : s) setA.insert(c); 
			if(setA.size() > 3) cout << s << endl;
		}
		q.push(s+"2"); q.push(s+"3"); q.push(s+"5"); q.push(s+"7");
	}
}

int main() {
	sync();
	int n; cin >> n;
	genAll(n);
	
	return 0;
}


