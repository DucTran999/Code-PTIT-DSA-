#include<bits/stdc++.h>
using namespace std;

int mc[20][20];
int c[100], d1[100], d2[100];
int X[100];
int m = INT_MIN;

void inp() {
	memset(c, 0, sizeof(0));
	memset(d1, 0, sizeof(0));
	memset(d2, 0, sizeof(0));
	memset(X, 0, sizeof(0));
	for(int i = 1; i <= 8 ; i++) {
		for(int j = 1; j <= 8; j++) {
			cin >> mc[i][j];
		}
	}
}

void check() {
	int sum = 0;
	for(int i = 1; i <= 8; i++) {
		sum += mc[i][X[i]];
	}
	if (sum > m) {
		m = sum;
	}
}

void Try(int i) {
	for(int j = 1; j <= 8; j++) {
		if(c[j] == 0 && d1[i+j-1] == 0 && d2[i-j+8] == 0) {
			X[i] = j;
			c[j] = d1[i+j-1] = d2[i-j+8] = 1;
			if(i == 8) {
				check();
			} else Try(i+1);
			c[j] = d1[i+j-1] = d2[i-j+8] = 0;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		Try(1);
		cout << m << endl;
		m = 0;
	}

	return 0;
}

