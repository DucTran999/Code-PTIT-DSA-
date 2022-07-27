#include<bits/stdc++.h>
using namespace std;
const int M = 123456789;

long long expo(long long a, long long k) {
	long long ans = 1;
	while(k) {
		if(k&1)
			ans = ((ans%M)*(a%M))%M;
		k >>= 1;
		a = ((a%M) * (a%M))%M;
	}
	return ans%M;
}

int main() {

	int t;
	cin >> t;
	long long n;
	while(t--) {
		cin >> n;
		if(n < 2) {
			cout << 1 << endl;
		} else {
			cout << expo(2,n-1)<< endl;
		}
	}
	return 0;
}

