#include<bits/stdc++.h>
using namespace std;
#define ll long long

int const M = 1e9+7;

vector<vector<ll>> Mul(vector<vector<ll>> &A, vector<vector<ll>> &B) {
	int sz = A.size();
	vector<vector<ll>> ans (sz, vector<ll>(sz, 0));
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < sz ; j++) {
			for(int  k = 0; k < sz ; k++) {
				A[i][k]%=M;
				B[k][j]%=M;
				ans[i][j] += (A[i][k]*B[k][j])%M;
				ans[i][j]%=M;
			}
		}
	}
	return ans;
}

vector<vector<ll>> matrixExpo(vector<vector<ll>> &A, ll k) {
	if(k == 1)
		return A;
	int sz = A.size();
	vector<vector<ll>> ans = matrixExpo(A, k>>1);
	ans = Mul(ans, ans);
	if(k & 1) ans = Mul(A, ans);
	return ans;
}

ll findSum(vector<vector<ll>> &A) {
	int sz = A.size();
	ll sum = 0;
	for(int i = 0; i < sz; i++) {
		sum = (sum%M + A[i][sz-1] %M)%M;
	}
	return sum%M;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<vector<ll>> A(n,vector<ll>(n,0));

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> A[i][j];
			}
		}
		A = matrixExpo(A, k);
		cout << findSum(A) << endl;
	}
	return 0;
}

