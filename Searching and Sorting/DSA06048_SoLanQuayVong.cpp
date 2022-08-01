#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		int ans = -1;
		cin >> n;
		vi a(n);
		for(int &i : a) cin >> i;
		--n;
		for(int i = 0; i < n; ++i)
			if(a[i] > a[i + 1]) ans = i + 1;
		if(ans == -1) {
			if(a[0] <= a[n - 1]) cout << 0 << endl;
			else cout << n << endl;
		} else cout << ans << endl;
	}

	return 0;
}


