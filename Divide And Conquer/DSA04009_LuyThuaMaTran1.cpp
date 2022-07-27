#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vvll vector<vector<ll>>
#define vl vector<long long>

int const M = 1e9+7;

vvll Mul(vvll &a, vvll &b) {
	int sz = a.size();
	vvll ans(sz, vl(sz,0));
	for(int i = 0; i < sz; i++)
		for(int j = 0; j < sz; j++)
			for(int k = 0; k < sz; k++) {
				a[i][k]%=M;
				b[k][j]%=M;
				ans[i][j] += (a[i][k]*b[k][j])%M;
				ans[i][j]%=M;
			}
	return ans;
}

vvll matrixExpo(vvll &a, ll k) {
	if(k == 1)
		return a;
	vvll ans = matrixExpo(a, k >> 1);
	ans = Mul(ans, ans);
	if(k&1) ans = Mul(a,ans);
	return ans;
}

void in(vvll &A) {
	for(auto tmp : A) {
		for(ll i : tmp) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n , k;
		cin >> n >> k;
		vvll A(n, vl(n,0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> A[i][j];
		A = matrixExpo(A, k);
		in(A);
	}
	return 0;
}

