/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vll;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));
const int mod = 1e9+7;

vll mul(vll &A, vll &B) {
	int sz = A.size();
	vll product(sz, vl(sz,0));
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < sz; j++) {
			for(int k = 0; k < sz; k++) {
				A[i][k]%=mod;
				B[k][j]%=mod;
				product[i][j] += (A[i][k]*B[k][j])%mod;
				product[i][j]%=mod;
			}
		}
	}
	return product;
}

vll expo(vll &A, ll k) {
	if(k == 1) return A;
	vll ans = expo(A, k>>1);
	ans = mul(ans, ans);
	if(k&1) ans = mul(A, ans);
	return ans;
}

ll sumLastCol(vll &A, int n) {
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		sum%=mod;
		sum+=A[i][n-1];
	}
	return sum%mod;
}

int main() {
	sync();
	ll t = 1, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		vll A(n,vl(n,0));
		for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) cin >> A[i][j];
		A = expo(A, k);
		cout << sumLastCol(A, n) << endl;
	}

	return 0;
}


