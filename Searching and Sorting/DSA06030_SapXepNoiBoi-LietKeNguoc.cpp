#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

void bubbleSort(int *A, int n) {
	vector<vector<int>> ans;
	for(int i = 0; i < n-1; ++i) {
		bool notSwap = 1;
		for(int j = 1; j < n -i ; ++j)
			if(A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				notSwap = 0;
			}
		if(notSwap) break;
		vector<int> v(n);
		for(int i = 0; i < n; ++i) v[i] = A[i];
		ans.push_back(v);
	}

	for(int i = ans.size(); i; --i) {
		cout << "Buoc " << i << ": " << ' ';
		for(int j : ans[i - 1]) cout << j << ' ';
		cout << endl;
	}
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int &i : A) cin >> i;
		bubbleSort(A, n);
	}

	return 0;
}


