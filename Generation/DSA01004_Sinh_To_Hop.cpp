#include<bits/stdc++.h>
using namespace std;

int A[100];
int n, k;
bool isLast;

void init() {
	cin >> n >> k;
	for(int i = 1; i <= k; i++) {
		A[i] = i;
	}
}

void gen_Com() {
	int i = k;
	while(i > 0 && A[i] == n - k + i) {
		i--;
	}
	if(i == 0) {
		isLast = true;
	} else {
		A[i]++;
		for(int j = i + 1; j <= k; j++) {
			A[j] = A[j-1] + 1;
		}
	}
}

void in() {
	for(int i = 1; i <= k; i++) {
		cout << A[i];
	}
	cout << " ";
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		init();
		while(!isLast) {
			in();
			gen_Com();
		}
		isLast = false;
		memset(A, 0, sizeof(A));
		cout << endl;
	}
	return 0;
}

