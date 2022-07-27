#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

void doSort(int *A, int n) {
	vector<vector<int>> ans;
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; ++j)
			if(A[i] > A[j]) swap(A[i], A[j]);
		vector<int> v(n);
		for(int k = 0; k < n; k++) v[k] = A[k];
		ans.push_back(v);
	}

	for(int i = ans.size(); i; i--) {
		cout << "Buoc " << i << ": ";
		for(int j : ans[i - 1]) cout << j << ' ';
		cout << endl;
	}
}

int main() {
	sync();
	int t = 1, n, m, x;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int &i : A) cin >> i;
		doSort(A, n);
	}
	return 0;
}


