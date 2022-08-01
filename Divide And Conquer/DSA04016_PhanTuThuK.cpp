#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m , k;
		cin >> n >> m >> k;
		vector<int>A(n);
		vector<int>B(m), ans(m+n);
		for(int i = 0; i<n; i++) {
			cin >> A[i];
		}
		for(int j = 0; j<m; j++) {
			cin >> B[j];
		}
		merge(A.begin(), A.end(), B.begin(), B.end(), ans.begin());
		cout << ans[k-1] << endl;
	}
	return 0;
}

