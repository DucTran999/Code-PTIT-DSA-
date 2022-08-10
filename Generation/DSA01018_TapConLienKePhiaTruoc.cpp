/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

void prev_Com(int *A, int n, int k) {
	int i = k;
	while(i > 0 and A[i] == A[i-1] + 1) --i;
	if(i == 0) {
		for(int j = 1; j <= k; j++) cout << n - k + j << " ";
	} else {
		A[i]--;
		if(A[k] != n) for(int j = i + 1; j<=k; j++) A[j]++;
		for(int j = 1; j <= k; j++) cout << A[j] << " ";
	}
	cout << endl;
}

int main() {
	sync();
	int t = 1, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int *A = new int[n+1];
		for(int i = 1; i<=k; i++) cin >> A[i];
		prev_Com(A, n, k);
		A = nullptr; delete(A);
	}

	return 0;
}


