#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int calc(int *A, int n) {
	int ans = INT_MAX;
	for(int i = 1; i <  n; i++)
		for(int j = i + 1; j <= n; j++)
			if(abs(ans) > abs(A[i] + A[j]))
				ans = A[i] + A[j];
	return ans;
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int A[n+1];
		for(int i = 1; i <= n; i++) cin >> A[i];
		cout << calc(A, n) << endl;
	}

	return 0;
}


