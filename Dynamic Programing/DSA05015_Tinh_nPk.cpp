#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9+7;

int main() {

	int t = 1;
	cin >> t;
	int n, k;

	while(t--) {
		cin >> n >> k;
		if(k > n) {
			cout << 0 << endl;
		} else {
			ll ans = 1;
			for(int i = n; i >= n-k+1 ; i--) {
				i%=M;
				ans = ((ans%M) * (i%M))%M;
			}
			cout << ans << endl;
		}	
	}

	return 0;
}

