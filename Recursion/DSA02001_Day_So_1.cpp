#include<bits/stdc++.h>
using namespace std;

int n;
int A[25];

void inp() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
	}
}

void in(int num) {
	cout << "[";
	for(int i = 1; i < num; i++) {
		cout << A[i] << " ";
	}
	cout << A[num] << "]" << endl;
}

void solve(int size) {
	if(size == 1) return;
	else {
		for(int i = 1; i < size; i++) {
			A[i] = A[i] + A[i+1];
		}
		in(size -1);
		solve(size - 1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		in(n);
		solve(n);
	}
	return 0;
}

