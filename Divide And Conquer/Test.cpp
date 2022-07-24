#include<bits/stdc++.h>
using namespace std;

int n;
int A[100];
// 0 : 8  1: 6
bool check() {
	if(A[1] != 0 || A[n] != 1)
		return false;
	for(int i = 1 ; i < n; i++) {
		if(A[i] == 0 && A[i+1] == 0)
			return false;
	}
	for(int i = 1 ; i < n - 2; i++) {
		if(A[i] == 1 && A[i+1] == 1 && A[i+2] == 1 && A[i+3] == 1)
			return false;
	}
	return true;
}

void Try(int i) {
	int j;
	for(j = 1; j >=0 ; j--) {
		A[i] = j;
		if(i == n) {
			if(check()) {
				for(int i = 1; i <= n; i++) {
					if(A[i] == 0) {
						cout << '8';
					} else {
						cout << '6';
					}
				}
				cout << endl;
			}
		} else Try(i+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int t=1;
//	cin >> t;
	while(t--) {
		memset(A, 0, sizeof(A));
		cin >> n;
		Try(1);
	}
	return 0;
}
