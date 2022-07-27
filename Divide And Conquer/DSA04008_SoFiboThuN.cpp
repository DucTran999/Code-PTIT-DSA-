#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9+7;

vector<vector<ll>> mul(vector<vector<ll>> &a, vector<vector<ll>> &b) {
	int sz = a.size();
	vector<vector<ll>> ans (sz, vector<ll>(sz, 0));
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < sz; j++) {
			for(int k = 0; k < sz; k++) {
				a[i][k]%=M;
				b[k][j]%=M;
				ll tmp = (a[i][k]*b[k][j])%M;
				ans[i][j] = (tmp + ans[i][j]%M)%M;
			}
		}
	}
	return ans;
}

vector<vector<ll>> matrixExp(vector<vector<ll>> &a, int n) {
	if(n == 0) {
		int sz = a.size();
		vector<vector<ll>> ans (sz, vector<ll>(sz, 0));
		for(int i = 0; i<sz; i++) {
			ans[i][i] = 1;
			return ans;
		}
	}
	if(n == 1) {
		return a;
	}
	vector<vector<ll>> tmp = matrixExp(a, n >> 1);
	vector<vector<ll>> ans = mul(tmp, tmp);
	if(n&1) {
		ans = mul(ans,a);
	}
	return ans;
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<vector<ll>> a = {{1,1}, {1,0}};
		vector<vector<ll>> ans = matrixExp(a, n);
		cout << ans[1][0] << endl;
	}
	return 0;
}

