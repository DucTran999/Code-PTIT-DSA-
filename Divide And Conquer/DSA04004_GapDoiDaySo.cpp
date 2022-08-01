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

long long FindK(long long n, long long k) {
	ll mid = expo(2,n-1);
	if(k == mid) return n;
	if(k > mid)
		return FindK(n-1, k - mid);
	return FindK(n-1, k);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long n, k;
		cin >> n >> k;
		cout << FindK(n, k) << endl;
	}
	return 0;
}
