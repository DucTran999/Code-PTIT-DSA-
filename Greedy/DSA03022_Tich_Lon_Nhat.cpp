#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll max (ll a, ll b, ll c, ll d, ll e) {
	ll max1 = max(a,b);
	ll max2 = max(c,d);
	return max(max(max1, max2), e);
}

int main() {
	int n;
	cin >> n;
	int A[n+1];
	for(int i = 0; i<n; i++) cin >> A[i];
	sort(A,A+n, greater<int>());
	ll a1 = A[1]*A[2]*A[0];
	ll a2 = A[0]*A[1];
	ll a3 = A[n-1]*A[n-2]*A[n-3];
	ll a4 = A[n-1]*A[n-2];
	ll a5 = A[n-1]*A[n-2]*A[0];
	cout << max (a1, a2, a3, a4, a5) << endl;

	return 0;
}

