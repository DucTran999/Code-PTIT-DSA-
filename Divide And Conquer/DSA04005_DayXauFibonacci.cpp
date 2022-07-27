#include<bits/stdc++.h>
using namespace std;

long long fi[100];

void fibo() {
	fi[0] = 0;
	fi[1] = 1;
	for(int i = 2; i <= 92; i++) {
		fi[i] = fi[i-1] + fi[i-2];
	}
}

char findK(int n, long long k) {
	if(n == 1) return 'A';
	if(n == 2) return 'B';
	if(k >  fi[n-2])
		return findK(n-1, k - fi[n-2]);
	return findK(n-2, k);
}

int main() {
	fibo();
	int t;
	cin >> t;
	while(t--) {
		long long n, k;
		cin >> n >> k;
		cout << findK(n, k)<< endl;
	}

	return 0;
}

