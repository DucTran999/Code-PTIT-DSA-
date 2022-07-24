#include<bits/stdc++.h>
using namespace std;

void solve(int *A, int n) {
	stack<int> st, st2;
	int R[n], R2[n];

	for(int i = n-1; i >= 0; i--) {
		while(st.size() and A[i] >= A[st.top()] ) st.pop();
		if(st.empty()) R[i] = -1;
		else R[i] = st.top();
		st.push(i);
	}

	for(int i = n-1; i >= 0; i--) {
		while(st2.size() and A[i] <= A[st2.top()]) st2.pop();
		if(st2.empty()) R2[i] = -1;
		else R2[i] = st2.top();
		st2.push(i);
	}

	for (int i=0; i< n; i++) {
		if(R[i] != -1 && R2[R[i]] != -1)
			cout << A[R2[R[i]]] << ' ';
		else
			cout<< -1 <<' ';
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int A[n];
		for(int &i : A) cin >> i;
		solve(A, n);
	}

	return 0;
}

