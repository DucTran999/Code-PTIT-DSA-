#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<ll> A(n),B(n);
		for(int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> B[i];
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end(), greater<int>());
		ll sum = 0;
		for(int i = 0; i <n; i++) {
			sum+= A[i]*B[i];
		}
		cout << sum << endl;
	}
	return 0;
}

