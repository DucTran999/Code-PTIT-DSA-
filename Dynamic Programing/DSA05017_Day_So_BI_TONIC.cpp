#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int A[n];
		for(int i = 0; i < n; i++)
			cin >> A[i];
		int dpL[n], dpR[n];

		for(int i = 0; i < n; ++i) {
			dpL[i] = A[i];
			for(int j = 0; j < i; ++j)
				if(A[i] > A[j]) dpL[i] = max(dpL[i], dpL[j] + A[i]);
		}

		for(int i = n - 1; i >= 0; --i) {
			dpR[i] = A[i];
			for(int j = n - 1; j > i; --j)
				if(A[i] > A[j]) dpR[i] = max(dpR[i], dpR[j] + A[i]);
		}

		int res = -1;
		for(int i = 0; i < n; ++i)
			res = max(res, dpL[i] + dpR[i] - A[i]);
		cout << res << endl;
	}
	return 0;
}
