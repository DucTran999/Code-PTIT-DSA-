/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

/*MSP: Maximum subarray problem*/

ll MSP(int *A, int n) {
	int prev_record = *A, ans = INT_MIN;
	for(int i = 1; i<n; i++) {
		if(prev_record > 0) prev_record += A[i];
		else prev_record = A[i];
		ans = max(ans, prev_record);
	}
	return ans;
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int &i : A) cin >> i;
		cout << MSP(A, n) << endl;
	}

	return 0;
}


