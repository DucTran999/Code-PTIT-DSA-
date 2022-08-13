/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

const int mod = 1e9+7;

ll expo(ll a, int k) {
	ll ans = 1;
	while(k) {
		if(k&1) ans = (ans*a)%mod;
		k>>=1;
		a = (a*a)%mod;
	}
	return ans;
}

int main() {
	sync();
	int t = 1, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cout << expo(n, k) << endl;
	}

	return 0;
}


