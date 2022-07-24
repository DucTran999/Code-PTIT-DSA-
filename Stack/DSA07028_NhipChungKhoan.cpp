#include<bits/stdc++.h>
using namespace std;

void stock(int *A, int n) {
	stack<int> st;
	int R[n+1];
	memset(R, 0, sizeof(R));
	for(int i = 1; i <= n; i++) {
		while(st.size() and A[i] >= A[st.top()]) st.pop();
		if(st.empty()) R[i] = 0;
		else R[i] = st.top();
		st.push(i);
	}
	for(int i = 1; i <= n; i++) {
		cout << i - R[i] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t = 1;
	cin >> t;
	int n;
	while(t--) {
		cin >> n;
		int A[n];
		for(int i = 1; i <= n; i++) {
			cin >> A[i];
		}
		stock(A, n);
	}
	return 0;
}

