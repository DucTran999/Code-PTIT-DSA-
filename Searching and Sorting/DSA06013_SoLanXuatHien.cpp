#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int t = 1, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		vector<int> A(n);
		for(int &i : A) cin >> i;
		int l = lower_bound(A.begin(), A.end(),k) - A.begin();
		int r = upper_bound(A.begin(), A.end(),k) - A.begin();
		if(A[l] != k) cout << -1 << endl;
		else cout << r - l << endl;
	}

	return 0;
}


