#include<bits/stdc++.h>
using namespace std;

bool comp(char c) {
	return (c == 'A' || c == 'E');
}

bool check(string s) {
	for(int i = 1 ; i < s.length()-1; i++) {
		if(comp(s[i])) {
			if(!comp(s[i - 1]) and !comp(s[i + 1]))
				return false;
		}
	}
	return true;
}

int main() {
	char c;
	cin >> c;
	string s = "ABC";
	for(int j = 'D'; j <= c; j++) {
		s+=j;
	}
	do {
		if(check(s))
			cout << s << endl;
	} while(next_permutation(s.begin(), s.end()));

	return 0;
}
