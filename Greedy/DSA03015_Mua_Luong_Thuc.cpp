#include<bits/stdc++.h>
using namespace std;

int binSearch(int N, int M, int S, int l, int r) {
	int ans = -1;
	while(l <= r) {
		int mid = l+(r-l)/2;
		int maxFood = (mid - mid/7)*N;
		if(maxFood >= S*M) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	if(ans != 1) ans-=(ans/7);
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int N, S, M;
		cin >> N >> S >> M;
		int maxDay = (S/7)*6 + S%7;
		if(N*maxDay < S*M) {
			cout << -1 << endl;
		} else {
			cout << binSearch(N,M, S, 1, S) << endl;
		}
	}

	return 0;
}

