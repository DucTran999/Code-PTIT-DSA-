#include<bits/stdc++.h>
using namespace std;

int A[11];
string s;

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> s;
		do {
			cout << s << " ";
		} while(next_permutation(s.begin(), s.end()));
		cout << endl;
	}

	return 0;
}

