#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005];
ll dp[100005];
bool ok = false;

bool check(ll n, ll k) {
	if(n == 1)
		return k == a[0];

	if(k == 0) {
		return ok;
	}

	dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i-1] + a[i];
	}
	int r = lower_bound(dp, dp+n, k) - dp;
	if(r > -1 and r < n) {
		if(dp[r] == k)
			return true;
		else {
			for(int i = r; i < n; i++) {
				int l = lower_bound(dp, dp+n, dp[i] - k) - dp;
				if (l > -1 and l < n and (dp[l] == dp[i] - k)) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	int t;
	cin >> t;
	ll n, k;
	while(t--) {
		ok = false;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] == 0) ok = true;
		}
		if (!check(n,k)) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
	return 0;
}
