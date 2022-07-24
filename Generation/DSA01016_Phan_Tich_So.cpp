#include<bits/stdc++.h>
using namespace std;

int n;
int A[25];
int num;
bool isLast;

void init(int n) {
	num = 1;
	A[1] = n;
}

void in(int n) {
	int i;
	cout << "(";
	for(i = 1; i < num; i++) {
		cout << A[i] << " ";
	}
	cout << A[i] << ") ";
}

void part() {
	int i = num;
	while(i > 0 && A[i] == 1) i--;

	if(i > 0) {
		A[i]--;
		int d = num + 1 - i;
		num = i;
		int q = d / A[i];
		int r = d % A[i];
		if(q) {
			for(int j = 1; j <= q; j++) {
				A[++num] = A[i];
			}
		}
		if(r) {
			A[++num] = r;
		}

	} else
		isLast = true;
}

int main() {

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		init(n);
		while(!isLast) {
			in(n);
			part();
		}
		isLast = false;
		cout << endl;
	}

	return 0;
}

