#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll Merge(ll *a, ll l, ll r, ll mid) {

	ll i, j, k;
	ll n1 = mid - l + 1, n2 = r - mid;
	ll L[n1], R[n2];

	for(i = 0; i < n1; ++i) L[i] = a[l + i];
	for(i = 0; i < n2; ++i) R[i] = a[mid + i + 1];
	ll res = 0;
	i = j = 0;
	k = l;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) a[k++] = L[i++];
		else {
			a[k++] = R[j++];
			res += n1 - i;
		}
	}
	while(i < n1) a[k++] = L[i++];
	while(j < n2) a[k++] = R[j++];
	return res;
}

ll tinh(ll *a, int l, int r) {
	ll ans = 0;
	int mid;
	if(l < r) {
		mid = (l + r)/2;
		ans += tinh(a, l, mid);
		ans += tinh(a, mid + 1, r);
		ans += Merge(a, l, r, mid);
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll a[n];
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << tinh(a, 0, n - 1) << endl;
	}

	return 0;
}
