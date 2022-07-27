#include<bits/stdc++.h>
using namespace std;

const long long M = 1e9+7;

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
	string n, k;
	while(t--) {
		cin >> n;
		k = n;
		reverse(k.begin(), k.end());
		cout << expo(stoll(n),stoll(k)) << endl;
	}

	return 0;
}

