#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve (vector<ll>& A, vector<ll>& B, vector<ll>& C) {
	int indA = 0, indB = 0, indC = 0;
	int ok = 0;
	while(indA < A.size() && indB < B.size() && indC < C.size()) {
		if(A[indA] == B[indB] && B[indB] == C[indC]) {
			cout << A[indA] << " ";
			indA++;
			indB++;
			indC++;
			ok = 1;
		} else if(A[indA] < B[indB]) indA++;
		else if(B[indB] < C[indC]) indB++;
		else indC++;
	}
	cout << endl;
	if(ok == 0)cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<ll> A(n), B(m), C(k);
		for(int i = 0; i < n; i++) cin >> A[i];
		for(int i = 0; i < m; i++) cin >> B[i];
		for(int i = 0; i < k; i++) cin >> C[i];
		solve(A,B,C);
	}
	return 0;
}

