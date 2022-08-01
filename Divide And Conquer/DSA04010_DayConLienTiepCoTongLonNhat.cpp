#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll max (ll a, ll b) {
	return (a > b) ? a : b;
}
void inp(int A[], int B[], int n) {
	for(int i = 1; i <=n; i++) {
		cin >> A[i];
		B[i] = 0;
	}
}

long long solve(int A[], int E[], int n) {
	if(n == 1) return A[1];
	E[1] = A[1];
	ll theMax = LONG_MIN;
	for(int i =2; i<=n; i++) {
		if(E[i-1] > 0) {
			E[i] = E[i-1] + A[i];
		} else {
			E[i] = A[i];
		}
		theMax = max(theMax, E[i]);
	}
	return theMax;
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int A[n+1], E[n+1];
		inp(A, E, n);
		cout << solve(A,E, n) << endl;
	}

	return 0;
}

