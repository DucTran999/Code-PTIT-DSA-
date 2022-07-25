#include<bits/stdc++.h>
using namespace std;

void solve(int *A, int n) {
	int l = 0, r = n-1;
	for(int i = 0; i < n; i++) {
		if(i&1) {
			cout << A[l] << " ";
			l++;
		} else {
			cout << A[r] << " ";
			r--;
		}
	}
	cout << endl;
}

int main() {
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int &i : A) cin >> i;
		sort(A, A+n);
		solve(A, n);
	}

	return 0;
}

