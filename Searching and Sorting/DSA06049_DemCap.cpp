#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

int main() {
	sync();
	int t = 1;
	cin >> t;
	int n, A[100005], k;
	while(t--) {
		cin >> n >> k;
		for(int i = 0; i < n; ++i) cin >> A[i];
		sort(A, A + n);
		ll cnt = 0;
		for(int i = 0; i < n; ++i)
			cnt += lower_bound(A + i + 1, A + n, k + A[i]) - A - i - 1;
		cout << cnt << endl;
	}
	return 0;
}


