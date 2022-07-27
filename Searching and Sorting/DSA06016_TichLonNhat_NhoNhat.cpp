#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int t = 1, n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		long long A[n], B[m];
		for(long long &i : A) cin >> i;
		for(long long &i : B) cin >> i;
		sort(A, A+n);
		sort(B, B+m);
		cout << A[n-1]*B[0] << endl;
	}

	return 0;
}


