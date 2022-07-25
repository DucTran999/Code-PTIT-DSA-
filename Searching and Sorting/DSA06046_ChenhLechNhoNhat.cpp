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
		cin >> n;
		vi A(n);
		for(int &i : A) cin >> i;
		sort(A.begin(), A.end());
		int ans = INT_MAX;
		for(int i = 1; i < n; ++i) ans = min(ans, A[i] - A[i - 1]);
		cout << ans << endl;
	}

	return 0;
}


