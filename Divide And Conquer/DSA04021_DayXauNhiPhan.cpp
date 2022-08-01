#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll size[100];

void fibo() {
	size[0] = 0;
	size[1] = 1;
	for(int i = 2; i <= 92; i++) {
		size[i] = size[i-1] + size[i-2];
	}
}

char findK(int n, long long k) {
	if(n == 1) return '0';
	if(n == 2) return '1';
	if(k > size[n-2])
		return findK(n-1, k - size[n-2]);
	return findK(n-2, k);
}

int main() {
	fibo();
	int t;
	cin >> t;
	ll n, k;
	while(t--) {
		cin >> n >> k;
		cout << findK(n,k)<< endl;
	}
	return 0;
}

