/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));
const int mod = 1e9+7;

ll expo (ll a, ll k) {
	if(k == 0) return 1;
	ll ans = expo(a, k >> 1)%mod;
	ans = (ans*ans)%mod;
	if(k&1) ans = (ans*a)%mod;
	return ans;
}

int main() {
	sync();
	int t = 1;
	string n, e;
	cin >> t;
	while(t--) {
		cin >> n;
		e = n;
		reverse(e.begin(), e.end());
		cout << expo(stoll(n), stoll(e)) << endl;
	}

	return 0;
}


