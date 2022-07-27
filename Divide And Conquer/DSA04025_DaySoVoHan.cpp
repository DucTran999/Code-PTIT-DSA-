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

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vvll A = {{1,1},{1,0}};
		A = matrixExpo(A,n);
		cout << A[1][0] << endl;
	}
	return 0;
}

