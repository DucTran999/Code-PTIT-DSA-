#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, i;
	cin >> n;
	unordered_map<int, bool> ump;
	while(cin >> i) {
		if(!ump[i]) {
			cout << i << ' ';
			ump[i] = 1;
		}
	}
	cout << endl;
	return 0;
}

