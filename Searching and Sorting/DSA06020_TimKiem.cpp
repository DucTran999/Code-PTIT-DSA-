#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int binSearch(int *A, int n, int k) {
	int l = 0, r = n - 1;
	while(l <= r) {
		int mid = l + (r-l)/2;
		if(A[mid] == k) return 1;
		else if (A[mid] < k) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

int main() {
	sync();
	int t = 1, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int A[n];
		for(int &i : A) cin >> i;
		cout << binSearch(A, n, k) << endl;
	}

	return 0;
}


