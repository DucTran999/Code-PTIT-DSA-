#include<bits/stdc++.h>
using namespace std;

long long max(long long a, long long b) {
	return (a > b) ? a : b;
}

long long maxArea(long long *A, int n) {
	stack<int> st;
	long long res = INT_MIN;
	int i = 0;
	while(i < n) {
		if(st.empty() or A[i] >= A[st.top()]) {
			st.push(i);
			++i;
		} else {
			int r = st.top();
			st.pop();
			if(st.empty()) {
				res = max(res, i*A[r]);
			} else {
				res = max(res, A[r] * (i - st.top() -1));
			}
		}
	}

	while(st.size()) {
		int r = st.top();
		st.pop();
		if(st.empty()) {
			res = max(res, i*A[r]);
		} else {
			res = max(res, A[r] * ( i - st.top() -1));
		}
	}

	return res;
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		long long A[n];
		for(long long &i : A) cin >> i;
		cout << maxArea(A, n) << endl;
	}
	return 0;
}

