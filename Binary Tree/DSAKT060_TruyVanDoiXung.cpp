#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);


bool isPalindrome(string s, int l, int r) {
	while(l < r) {
		if(s[l] != s[r])
			return false;
		l++;
		r--;
	}
	return true;
}

int main() {
	sync();
	string s;
	cin >> s;
	s = 'x'+ s;
	int t = 0;
	cin >> t;
	char rq;
	while(t--) {
		cin >> rq;
		if(rq == 'q') {
			int x, y;
			cin >> x >> y;
			if(isPalindrome(s, x, y)) {
				cout << "YES";
			} else cout << "NO";
			cout << endl;
		} else {
			int a = 0;
			char b;
			cin >> a >> b;
			s[a] = b;
		}
	}
	s.clear();
	return 0;
}


