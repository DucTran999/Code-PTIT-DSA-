#include<bits/stdc++.h>
using namespace std;

int n, k;
int A[25];
int B[25];


void inp() {
	cin >> n >> k;
	for(int i = 1; i <= k; i++) {
		cin >> A[i];
	}
	for(int i = 1; i <= k; i++) {
		B[i] = i;
	}
}

bool check() {
	for(int i = 1; i <= k; i++) {
		if(B[i] != A[i])
			return false;
	}
	return true;
}

void sinh() {
	int i = k;
	while(i > 0 && B[i] == n-k+i) i--;
	if(i == 0) {
		return;
	} else {
		B[i]++;
		for(int j = i + 1; j <= k; j++) {
			B[j] = B[j-1] + 1;
		}
	}
}

int main() {
	int t;
	cin>> t;
	while(t--) {
		inp();
		int cnt = 1;
		while(check() == false) {
			cnt++;
			sinh();
		}
		cout << cnt << endl;
	}

	return 0;
}



