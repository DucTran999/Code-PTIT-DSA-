/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));
ll f[100];

void fibo() {
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i <= 46; i++) {
		f[i] = f[i-1]+f[i-2];
	}
}

ll cntK(int n, ll k) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(k > f[n-1]) return (cntK(n-1, f[n-1]) + cntK(n-2, k - f[n-1]));
	return cntK(n-1, k);
}

int main() {
	sync();
	fibo();
	ll t = 1, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		cout << cntK(n, k) << endl;
	}

	return 0;
}


