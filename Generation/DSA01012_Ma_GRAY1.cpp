#include<bits/stdc++.h>
using namespace std;

int n;
int A[100];
int Gray[100];
bool isLast;

void init() {
	for(int i = 1; i <= n; i++) {
		A[i] = 0;
		Gray[i] = 0;
	}
}

void in() {
	for(int i = 1; i <= n; i++) {
		cout << Gray[i];
	}
	cout << " ";
}

void genGray() {
	int i = n;
	while(i > 0 && A[i] == 1) {
		A[i] = 0;
		--i;
	}
	if(i == 0) isLast =true;
	else A[i] = 1;

	Gray[1] = A[1];

	for(int i = 1; i < n; i++) {
		if(A[i] != A[i+1]) {
			Gray[i+1] = 1;
		} else {
			Gray[i+1] = 0;
		}
	}
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		cin >> n;
		while(!isLast) {
			in();
			genGray();
		}
		isLast = false;
		cout << endl;
	}

	return 0;
}

