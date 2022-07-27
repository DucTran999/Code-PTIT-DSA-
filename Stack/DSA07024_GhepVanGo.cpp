#include <bits/stdc++.h>
using namespace std;

long long calc(long long *A, int n) {
	long long ans = 0;
	stack<int> st, st2;
	long long L[n+1], R[n+1];
	memset(L, 0, sizeof(L));
	memset(R, 0, sizeof(R));

	for(int i = 1; i <= n; i++) {
		while(!st.empty() and A[i] <= A[st.top()])	st.pop();
		if(!st.empty()) L[i] = st.top();
		else L[i] = 0;
		st.push(i);
	}

	for (int i = n; i >= 1; i--) {
		while(!st2.empty() and A[i] <= A[st2.top()]) st2.pop();
		if(st2.empty()) R[i] = n+1;
		else R[i] = st2.top();
		st2.push(i);
	}
	for(int i = 1; i <=n; i++) {
		if((R[i] - L[i]-1) >= A[i]) ans = max(ans, A[i]);
	}

	return ans;
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		long long A[n+1];
		A[0] = 0;
		for (int i = 1; i <= n; i++) cin >> A[i];
		cout << calc(A, n) << endl;
	}
}
