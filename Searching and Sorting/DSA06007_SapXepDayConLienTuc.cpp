#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> A(n), B(n);
		for(int &i : A) cin >> i;
		B = A;
		sort(A.begin(), A.end());
		for(int i = 0; i < n; ++i) {
			if(A[i] != B[i]) {
				cout << i + 1 << ' ';
				break;
			}
		}
		for(int i = n - 1; i; --i) {
			if(A[i] != B[i]) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}

