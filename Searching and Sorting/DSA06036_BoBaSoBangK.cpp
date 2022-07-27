#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

string check(int *A, int n, int k) {
	int l, r;
	for(int i = 0; i < n; ++i) {
		l = i + 1;
		r = n - 1;
		while(l < r) {
			if(A[i] + A[l] + A[r] == k) return "YES";
			if(A[i] + A[l] + A[r] < k) ++l;
			else --r;
		}
	}
	return "NO";
}

int main() {
	sync();
	int t = 1, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int A[n];
		for(int &i : A) cin >> i;
		sort(A, A + n);
		cout << check(A, n, k) << endl;
	}

	return 0;
}


