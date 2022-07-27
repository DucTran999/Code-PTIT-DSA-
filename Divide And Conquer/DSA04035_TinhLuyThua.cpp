#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int M = 1e9+7;

ll binPow(ll a, ll b) {
	if(b == 0) return 1;
	ll ans = binPow(a, b>>1);
	ans = ((ans%M)*(ans%M))%M;
	if(b&1)	ans = ((ans%M) * (a%M))%M;
	return ans%M;
}

int main() {

	while(1) {
		ll a, b;
		cin >> a >> b;
		if(a == 0 && b == 0) {
			break;
		}
		cout << binPow(a, b) << endl;
	}

	return 0;
}

