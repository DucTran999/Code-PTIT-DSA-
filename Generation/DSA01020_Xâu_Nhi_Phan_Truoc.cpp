#include<bits/stdc++.h>
using namespace std;

void prev_bin(string s) {
	int i = s.size()-1;
	while (i > -1 && s[i] == '0') {
		s[i] = '1';
		i--;
	}
	if(i < 0) {
		cout << s <<endl;
	} else {
		s[i] = '0';
		cout << s << endl;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>> t;
	while(t--) {
		string s;
		cin >> s;
		prev_bin(s);
	}

	return 0;
}



