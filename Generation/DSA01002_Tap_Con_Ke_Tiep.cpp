#include<bits/stdc++.h>
using namespace std;

int A[100];
int n, k;
int ok = 0;

void inp() {
	cin >> n >> k;
	for(int i = 1 ; i <= k; i++) {
		cin >> A[i];
	}
}

void in() {
	if(ok == 1) {
		for(int i = 1; i <= k; i++) {
			cout << i << " ";
		}
	} else {
		for(int i = 1; i <= k; i++) {
			cout << A[i] << " ";
		}
	}
	cout << endl;
	ok = 0;
}

void nextCom() {
	int i = k;
	while(i > 0 && A[i] == n-k+i) {
		i--;
	}
	if(i == 0 ) {
		ok = 1;
	} else {
		A[i]++;
		for(int j = i+1; j <=k; j++) {
			A[j] = A[j-1] + 1;
		}
	}
}

int main() {
	
	int t;
	cin>> t;
	while(t--) {
		inp();
		nextCom();
		in();
		memset(A, 0, sizeof(A));
	}

	return 0;
}



