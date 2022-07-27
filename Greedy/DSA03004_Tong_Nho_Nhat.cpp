#include<bits/stdc++.h>
using namespace std;
#define ll long long
void inp(int *A, int n) {
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A, A+n);
}

void solve(int *A, int n) {
	ll a = 0, b = 0;
	for(int i = 0; i < n; i++) {
		if(i&1) {
			a = a*10 + A[i];
		} else {
			b = b*10 + A[i];
		}
	}
	cout << a + b << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int A[n];
		inp(A, n);
		solve(A,n);
	}
	return 0;
}

