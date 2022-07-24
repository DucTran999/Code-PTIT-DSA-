#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string s1,s2;
		cin >> s1 >> s2;
		bitset<30> b1(s1);
		bitset<30> b2(s2);
		cout << b1.to_ulong() * b2.to_ulong() << endl;
	}

	return 0;
}

