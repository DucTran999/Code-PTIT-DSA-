#include<bits/stdc++.h>
using namespace std;

int countPair(int A[], int n, int k) {
	unordered_map<int, int> um;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (um.find(k - A[i]) != um.end()) {
			cnt += um[k - A[i]];
		}
		um[A[i]]++;
	}
	return cnt;
}

int main() {
	int t = 1, n, k, x;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		int A[n];
		for(int &i : A) cin >> i;
		cout<< countPair(A, n, k) << endl;
	}
	return 0;
}

