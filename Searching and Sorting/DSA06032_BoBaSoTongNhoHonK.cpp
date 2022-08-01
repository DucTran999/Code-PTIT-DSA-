#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int t = 1;
	cin >> t;
	ll n, k, tmp, ind;
	while(t--) {
		ll cnt = 0;
		cin >> n >> k;
		ll A[n];
		for(ll &i : A) cin >> i;
		sort(A, A + n);
		for(int i = 0; i < n; ++i) {
			if(A[i] > k) break;
			for(int j = i + 1; j < n; ++j) {
				ind = upper_bound(A + j + 1, A + n, k - A[i] - A[j] - 1) - A;
				if(ind > j) cnt += ind - j - 1;
				else break;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}


