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
		vi A(n);
		for(int &i : A) cin >> i;
		sort(A.begin(), A.end());
		A.erase(unique(A.begin(), A.end()), A.end());
		int L = A[0], R = A[n-1];
		cout << R - L + 1 - A.size() << endl;
	}

	return 0;
}


