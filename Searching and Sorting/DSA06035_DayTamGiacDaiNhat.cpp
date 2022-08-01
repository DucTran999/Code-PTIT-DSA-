#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int t = 1, n, A[100005];
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) cin >> A[i];
		int inc[n], dec[n];
		inc[0] = dec[n - 1] = 1;
		for(int i = 1; i < n; i++) {
			if(A[i] > A[i - 1]) inc[i] = inc[i - 1] + 1;
			else inc[i] = 1;
		}
		for(int i = n - 2; i >= 0; --i) {
			if(A[i] > A[i + 1]) dec[i] = dec[i + 1] + 1;
			else dec[i] = 1;
		}
		int ans = -1;
		for(int i = 0; i < n; ++i) ans = max(ans, inc[i] + dec[i] - 1);
		cout << ans << endl;
	}

	return 0;
}


