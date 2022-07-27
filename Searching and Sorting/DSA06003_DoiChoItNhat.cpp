#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<int> A(n);
		for(int &i : A) cin >> i;

		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			int idx = i;
			for(int j = i + 1; j < n; ++j) if(A[idx] > A[j]) idx = j;
			if(idx != i)cnt ++;
			swap(A[i], A[idx]);
		}
		cout << cnt << endl;
	}
	return 0;
}

