#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

ll C[1005][1005];

void Calc() {
	for(int i = 0; i<= 1000; i++) {
		for(int j = 0; j <= i; j++) {
			if(i == 0 || j == i) {
				C[i][j] = 1;
			} else {
				C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
			}
		}
	}
}

int main() {
	Calc();
	int t = 1;
	cin >> t;
	int n, k;
	while(t--) {
		cin >> n >> k;
		cout << C[n][k] << endl;
	}
	return 0;
}
