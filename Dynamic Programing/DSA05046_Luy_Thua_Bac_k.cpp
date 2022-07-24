#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
const int MOD = 1e9+7;


int S[MAX][MAX], inv[MAX];

int expo(long long x, int n) {
	x %= MOD;
	long long res = 1;

	while (n) {
		if (n & 1) res = (res * x) % MOD;
		x = (x * x) % MOD;
		n >>= 1;
	}

	return (res % MOD);
}

void Generate() {
	int i, j;
	for (i = 0; i < MAX; i++) inv[i] = expo(i, MOD - 2);

	S[0][0] = 1;
	for (i = 1; i < MAX; i++) {
		S[i][0] = 0;
		for (j = 1; j <= i; j++) {
			S[i][j] = ( ((long long)S[i - 1][j] * j) + S[i - 1][j - 1]) % MOD;
		}
	}
}

int faulhaber(long long n, int k) {
	n %= MOD;
	if (!k) return n;

	int j;
	long long res = 0, p = 1;
	for (j = 0; j <= k; j++) {
		p = (p * (n + 1 - j)) % MOD;
		res = (res + (((S[k][j] * p) % MOD) * inv[j + 1])) % MOD;
	}

	return (res % MOD);
}

int main() {
	Generate();
	int t = 1;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		cout << faulhaber(n, k)<< endl;
	}

	return 0;
}

