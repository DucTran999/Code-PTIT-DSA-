#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
#define ll long long

void inp(int *A, int n) {
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A, A+n);
}

void solve(int *A, int n) {
	ll sum = 0;
	for(int i = 1; i < n; i++) {
		ll tmp = (A[i]*i)%M;
		sum = (sum%M + tmp)%M;
	}
	cout << sum << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int A[n];
		inp(A, n);
		solve(A, n);
	}

	return 0;
}

