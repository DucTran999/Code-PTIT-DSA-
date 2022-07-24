#include<bits/stdc++.h>
using namespace std;

int A[100];
int n, k;
int B[100];
bool isLast;
int cnt = 0;

void inp() {
	cin >> n >> k;
	for(int i = 1 ; i <= n; i++) {
		cin >> A[i];
	}
}

void init() {
	for(int i = 1; i<=k; i++) {
		B[i] = i;
	}
}

bool check() {
	for(int i = 1; i < k ; i++) {
		if(A[B[i]] > A[B[i+1]])
			return false;
	}
	return true;
}


void next_Com() {
	int i = k;
	while(i>0 && B[i] == n - k + i) {
		i--;
	}
	if(i == 0)
		isLast = true;
	else {
		B[i]++;
		for(int j = i + 1; j <= k; j++) {
			B[j] = B[j-1] + 1;
		}
	}
}

int main() {
	inp();
	init();
	while(!isLast) {
		if(check()) {
			cnt++;
		}
		next_Com();
	}
	cout << cnt << endl;;
	return 0;
}

