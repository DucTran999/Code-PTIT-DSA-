#include<bits/stdc++.h>
using namespace std;

int A[1000];
int n, k;
bool isLast;

void init() {
	for(int i = 1 ; i<= k; i++) {
		A[i] = i;
	}
}

void in() {
	for(int i =1; i <=k; i++) {
		cout << char(A[i]-1+ 'A');
	}
	cout << endl;
}

void Try(int i) {
	int j;
	for(j = A[i-1] + 1; j <= n; j++) {
		A[i] = j;
		if(i == k) {
			in();
		} else Try(i+1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		init();
		Try(1);
	}

	return 0;
}



