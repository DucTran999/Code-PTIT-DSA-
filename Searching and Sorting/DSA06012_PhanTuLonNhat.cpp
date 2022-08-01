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
		sort(A.begin(), A.end(), greater<int>());
		int idx = 0;
		while(k--) cout << A[idx++] << ' ';
		cout << endl;
	}

	return 0;
}


