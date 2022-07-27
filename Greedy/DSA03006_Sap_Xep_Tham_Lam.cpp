#include<bits/stdc++.h>
using namespace std;
int A[100];
int B[100];
int n;

void inp() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
		B[i] = A[i];
	}
	sort(B+1, B+n+1);
}

bool check() {
	int mid = n+1/2;
	for(int i =1; i < mid; i++) {
		if(A[i] != B[i] && A[i] != B[n-i+1])
			return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		if(check()) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}

