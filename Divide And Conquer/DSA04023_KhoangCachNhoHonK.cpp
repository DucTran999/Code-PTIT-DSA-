#include<bits/stdc++.h>
using namespace std;

void solve(int *a, int n, int k) {
	long long cnt = 0;
	sort(a, a + n);
	for(int i = 0; i < n-1; i++) {
		int id = upper_bound(a + i, a + n, a[i] + k - 1) - a;
		if(id > n) {
			cout << cnt <<endl;
			return;
		}
		cnt = cnt + 1LL*(id-i-1);
	}
	cout << cnt << endl;
}

int main() {

	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		solve(a, n, k);
	}
}
