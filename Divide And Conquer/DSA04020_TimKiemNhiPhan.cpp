/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int findK(int *A, int n, int k){
	int l = 0, r = n - 1;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(A[mid] == k) return mid + 1;
		else if(A[mid] < k) l = mid + 1;
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
		int A[n]; for(int &i : A) cin >> i;
		if(findK(A, n, k) > 0) cout << findK(A, n, k);
		else cout << "NO";
		cout << endl;
	}

	return 0;
}


