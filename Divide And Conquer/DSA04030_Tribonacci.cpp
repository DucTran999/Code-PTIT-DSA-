#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vvll vector<vector<ll>>
#define vl vector<ll>

const ll M = 1e15 + 7;

vvll Mul(vvll &a, vvll &b) {
	ll sz = a.size();
	vvll ans (sz, vl(sz, 0));
	for(ll i = 0; i < sz; i++) {
		for(ll j = 0; j < sz; j ++) {
			for(ll k = 0; k < sz; k++) {
				a[i][k]%=M;
				b[k][j]%=M;
				ans[i][j] += (a[i][k]*b[k][j])%M;
				ans[i][j]%=M;
			}
		}
	}
	return ans;
}

vvll matrixExpo(vvll &a, ll k) {
	if(k == 1) return a;
	vvll ans = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	while(k) {
		if(k&1)
			ans = Mul(ans, a);
		a = Mul(a, a);
		k>>=1;
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vvll A = {{1,1,1,0},{1,0,0,0}, {0,1,0,0},{1,1,1,1}};
		vvll B  = matrixExpo(A, n);
		cout << B[3][1] << endl;
	}
	return 0;
}


