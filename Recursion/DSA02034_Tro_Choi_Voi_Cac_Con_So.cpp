#include<bits/stdc++.h>
using namespace std;

int n;
int A[25];
void init() {
	for(int i = 1; i<=n; i++) {
		A[i]=i;
	}
}

bool check() {
	for(int i = 2; i < n; i++) {
		if(abs(A[i] - A[i-1]) == 1 || abs(A[i]- A[i+1]) == 1)
			return false;
	}
	return true;
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		init();
		do {
			if(check()) {
				for(int i = 1; i <= n; i++) {
					cout << A[i];
				}
				cout << endl;
			}
		} while(next_permutation(A+1, A+n+1));
	}

	return 0;
}

