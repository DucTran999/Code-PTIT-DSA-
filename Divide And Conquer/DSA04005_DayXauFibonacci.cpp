/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

ll f[100];
void fibo() {
	f[1] = 1; f[2] = 1;
	for(int i = 3; i < 93; i++) f[i] = f[i-2] + f[i-1];
}

char findK(ll n, ll k) {
	if(n == 1) return 'A';
	if(n == 2) return 'B';
	if(k > f[n-2]) return findK(n - 1, k - f[n-2]);
	return findK(n-2, k);
}

int main() {
	sync();
	fibo();
	int t = 1;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		cout << findK(n, k) << endl;
	}

	return 0;
}


