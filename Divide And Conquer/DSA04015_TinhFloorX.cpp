/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int floorX(int *A, int n, int x) {
	int idx = lower_bound(A, A + n, x) - A;
	if(idx > 0 and A[idx] == x) return idx+1;
	else if(idx > 0) return idx;
	return -1;
}

int main() {
	sync();
	int t = 1, n, x;
	cin >> t;
	while(t--) {
		cin >> n >> x;
		int A[n];
		for(int &i : A) cin >> i;
		cout << floorX(A, n, x) << endl;
	}

	return 0;
}


