#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll expo(ll a, ll k) {
	ll ans = 1;
	while(k) {
		if(k&1) ans*=a;
		k>>=1;
		a*=a;
	}
	return ans;
}

char findCharK(ll n, ll k) {
	ll mid = expo(2, n-1);
	if(k == mid) return n +'A'-1;
	if( k < mid) {
		return findCharK(n-1, k);
	}
	return findCharK(n-1, k - mid);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		cout << findCharK(n, k) << endl;
	}

	return 0;
}

