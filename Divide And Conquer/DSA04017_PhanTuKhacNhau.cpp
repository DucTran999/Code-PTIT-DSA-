#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<ll> &A, vector<ll>&B, int n) {
	ll ans = -1;
	if(A[0] != B[0]) return 0;
	if(A[n-1] != B[n-2]) return n-2;
	ll l = 1, r = n-2;
	while(l <= r) {
		ll mid = (l+r)>>1;
		if(B[mid] != A[mid]) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ans;
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<ll> A(n), B(n-1);
		for(int i = 0; i < n; i++) {
			cin>> A[i];
		}
		for(int j = 0; j < n-1; j++)
			cin >> B[j];
		cout << solve(A, B, n)+1 << endl;
	}

	return 0;
}

