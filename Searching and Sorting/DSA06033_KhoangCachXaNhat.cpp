#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n], MAX[n], ans = -1;
		for(int &i : A) cin >> i;

		MAX[n - 1] = A[n - 1];

		for(int i = n - 2; i >= 0; i--)
			MAX[i] = max(MAX[i + 1], A[i]);
		int i, j;
		i = j = 0;
		while(i < n and j < n) {
			if(MAX[j] > A[i]) {
				ans = max(ans, j - i);
				++j;
			} else ++i;
		}
		if(!ans) ans = -1;
		cout << ans << endl;
	}

	return 0;
}


