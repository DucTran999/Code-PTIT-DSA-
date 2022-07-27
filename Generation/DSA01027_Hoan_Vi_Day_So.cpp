#include<bits/stdc++.h>
using namespace std;

int input[100];
int A[1000];
int n;

void init() {
	for(int i = 1; i <= n; i++) {
		A[i] = i;
	}
}

void inp() {
	for(int i = 1; i <=n; i++) {
		cin >> input[i];
	}
	sort(input+1, input+n+1);
	init();
}

void in() {
	for(int i = 1; i<=n; i++) {
		cout << input[A[i]] <<" ";
	}
	cout << endl;
}

int main() {

	cin >> n;
	inp();
	do {
		in();
	} while(next_permutation(A+1,A+n+1));

	return 0;
}



