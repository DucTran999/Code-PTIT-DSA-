#include<bits/stdc++.h>
using namespace std;

void solve(int *A, int n){
	stack<int> st;
	int R[n];
	for(int i = n - 1; i >= 0; i--){
		while(!st.empty() and A[i] >= st.top()) st.pop();
		if(st.empty()) R[i] = -1;
		else R[i] = st.top();
		st.push(A[i]);
	}	
	for(int i = 0; i < n; i++){
		cout << R[i] <<" ";
	}
	cout << endl;
}

int main(){
	int t = 1, n;
	cin >> t;
	cin.ignore();
	while(t--){
		cin >> n;
		int A[n];
		for(int &i : A) cin >> i;
		solve(A, n);
	}
	return 0;
}

