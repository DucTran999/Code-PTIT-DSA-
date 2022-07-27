#include<bits/stdc++.h>
using namespace std;

int A[21];
int n;
void init() {
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		init();
		if(next_permutation(A+1, A+n+1) ) {
			for(int i = 1; i<= n; i++) {
				cout << A[i] << " ";
			}
		} else {
			for(int i = 1; i<= n; i++) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

