#include<bits/stdc++.h>
using namespace std;

int A[100];
int n, k;

void inp() {
	cin >> n >> k;
	for (int i = 1; i<=n; i++)
		cin>>A[i];
	sort(A + 1, A + n + 1);
}

void solve() {
	int sub1 = 0;
	int sub2 = 0;
	for(int i = 1; i <= n; i++) {
		if(i <= k  ) {
			sub1 += A[i];
			sub2 += A[n-i+1];
		} else {
			sub1 -= A[i];
			sub2 -= A[n-i+1];
		}
	}
	cout << max(abs(sub1), abs(sub2)) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		inp();
		solve();
	}
	return 0;
}

