#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
long long n, k;

int exponent() {
	long long ans = 1;
	while(k) {
		if(k&1) {
			ans = (ans*n)%mod;
		}
		k>>=1;
		n = (n*n)%mod;
	}
	return ans;
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cout << exponent() << endl;
	}

	return 0;
}

