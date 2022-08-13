/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

ll findDif(ll *A, ll *B, ll n) {
	ll ans = 0, l = 0, r = n-1;
	while(l <= r) {
		ll mid = (l+r)>>1;
		if(B[mid] != A[mid]) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ans+1;
}

int main() {
	sync();
	ll t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		ll A[n], B[n-1];
		for(int i = 0; i < n; i++) cin >> A[i];
		for(int i = 0; i < n-1; i++) cin >> B[i];
		cout << findDif(A, B, n) << endl;
	}

	return 0;
}


