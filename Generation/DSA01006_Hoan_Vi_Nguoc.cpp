#include<bits/stdc++.h>
using namespace std;

int A[100];
bool isLast;
int n;

void inp() {
	cin >> n;
	for(int i = 0; i  <= n; i++) {
		A[i] = n-i+1;
	}
}

void in() {
	for(int i = 1; i <= n; i++) {
		cout << A[i];
	}
	cout << " ";
}

void genPer() {
	int i = n-1;
	while(i > 0 && A[i] < A[i+1]) i--;
	if(i == 0) {
		isLast = true;
	} else {
		int j = n;
		while(A[j] > A[i])j--;
		swap(A[i], A[j]);
		int d = i + 1;
		int c = n;
		while(d<c) {
			swap(A[d], A[c]);
			d++;
			c--;
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
		while(!isLast) {
			in();
			genPer();
		}
		isLast = false;
		cout << endl;
		memset(A, 0, sizeof(A));
	}

	return 0;
}



