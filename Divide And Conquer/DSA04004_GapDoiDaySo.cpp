/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

ll expo(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1) ans*=a;
		b>>=1;
		a = a*a;
	}
	return ans;
}

int findK(ll n, ll k) {
	ll mid = expo(2, n-1);
	if(k == mid) return n;
	if(k < mid) return findK(n-1, k);
	return findK(n - 1, k - mid);
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		cout << findK(n, k) << endl;
	}

	return 0;
}


