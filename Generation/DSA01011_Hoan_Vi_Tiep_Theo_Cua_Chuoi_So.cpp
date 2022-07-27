#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int test;
		string s;
		cin >> test >> s;
		if(next_permutation(s.begin(), s.end())) {
			cout << test << " " << s << endl;
		} else {
			cout << test << " BIGGEST\n";
		}
	}
	return 0;
}

