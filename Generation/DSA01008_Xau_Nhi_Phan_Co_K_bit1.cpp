#include<bits/stdc++.h>
using namespace std;
int A[100];
int n, k;
bool isLast;

void in() {
	for(int i = 1; i <=n; i++) {
		cout << A[i];
	}
	cout << endl;
}

void inp() {
	cin >> n >> k;
	for(int i = n ; i > 0; i--) {
		if(k) {
			A[i] = 1;
			k--;
		} else {
			A[i] = 0;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>> t;
	while(t--) {
		inp();
		do {
			in();
		} while(next_permutation(A+1, A+n+1));
		memset(A, 0, sizeof(A));
	}

	return 0;
}



