#include<bits/stdc++.h>
using namespace std;

int A[1000];
int n;
bool isLast;

void init() {
	for(int i = 1 ; i<=n; i++) {
		A[i] = 0;
	}
}

void gen() {
	int i = n;
	while(i > 0 && A[i] == 1) {
		A[i] = 0;
		--i;
	}
	if(i == 0) {
		isLast = true;
	} else {
		A[i] = 1;
	}
}
bool check() {
	if(A[1] == 0 || A[n] == 1)
		return false;
	for(int i = 1; i < n; i++) {
		if(A[i] == 1 && A[i+1] == 1)
			return false;
	}
	return true;
}

void in() {
	for(int i = 1; i <= n; i++) {
		if(A[i] == 0)
			cout << "A";
		else
			cout << "H";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		init();
		while(!isLast) {
			if(check() == true) {
				in();
			}
			gen();
		}
		isLast = false;
	}

	return 0;
}



