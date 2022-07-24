#include<bits/stdc++.h>
using namespace std;

// 0 : 6 -  1 : 8
int A[1000];
int n;
bool isLast;

void init() {
	for(int i = 1 ; i<= n; i++) {
		A[i] = 0;
	}
}

void in() {
	for(int i = 1; i<=n; i++) {
		if(A[i] == 0) {
			cout << 6;
		} else cout << 8;
	}
	cout << endl;
}

bool check() {
	if(A[1] == 0 || A[n] == 1)
		return false;
	for(int i = 1; i <n; i++) {
		if(A[i] == 1 && A[i+1] == 1)
			return false;
	}
	for(int i = 0; i <= n - 3; i++) {
		if(A[i] == 0 && A[i + 1] == 0 && A[i+2] == 0 && A[i+3] == 0)
			return false;
	}
	return true;
}

void Try(int i) {
	int j;
	for(j = 0; j<=1 ; j++) {
		A[i] = j;
		if(i == n) {
			if(check()) {
				in();
			}
		} else Try(i+1);
	}
}

int main() {
	cin >> n;
	if(n >= 6) {
		init();
		Try(1);
	}

	return 0;
}



