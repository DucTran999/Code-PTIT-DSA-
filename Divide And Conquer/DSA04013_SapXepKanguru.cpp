#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<ll> A, ll n) {
	int mid = n/2;
	sort(A.begin(), A.end(),greater<ll>());
	ll ans = n;
	int j = mid;
	for(int i = 0; i < mid; i++) {
		int ok = 0;
		while(j < n) {
			if(A[i] >= 2*A[j]) {
				ok = 1;
				ans--;
				j++;
				break;
			}
			j++;
		}
		if(ok == 0) return ans;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<ll> A(n);
		for(int i = 0; i<n; i++) {
			cin >> A[i];
		}
		cout << solve(A, n) << endl;
	}
	return 0;
}

