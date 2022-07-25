#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> A(n);
		for(int &i : A) cin >> i;
		sort(A.begin(), A.end());
		for(int i : A) cout << i << ' ';
		cout << endl;
	}
	return 0;
}

