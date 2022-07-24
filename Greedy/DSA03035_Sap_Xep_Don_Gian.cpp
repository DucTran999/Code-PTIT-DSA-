#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n+5), f(n+5);
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		f[a[i]] = f[a[i] - 1] + 1;
		ans = max(ans, f[a[i]]);
	}

	cout << n - ans << endl;
	return 0;
}

