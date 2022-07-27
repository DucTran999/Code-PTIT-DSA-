#include<bits/stdc++.h>
using namespace std;

int A[100];
int n, k;
bool isLast;

void init() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		A[i] = i;
	}
}

void in() {
	for(int i = 1; i <= n; i++) {
		cout << A[i];
	}
	cout << " ";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		init();
		do {
			in();
		} while(next_permutation(A+1, A+n+1));
		cout << endl;
	}
	return 0;
}

