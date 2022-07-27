#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

bool notPrime[1000010];

void sieve() {
	notPrime[0] = notPrime[1] = true;
	for(int i = 2; i*i <= 1e6+5; i++) {
		if(notPrime[i] == false) {
			for(int j = i*i; j <= 1e6+5; j+=i)
				notPrime[j] = true;
		}
	}
}

int calc(int &n) {
	int mid = n >> 1;
	for(int i = 2; i <= mid; ++i)
		if(!notPrime[i] and !notPrime[n - i]) return i;
	return -1;
}

int main() {
	sync();
	sieve();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int ans = calc(n);
		if(ans == -1) cout << ans << endl;
		else cout << ans << ' ' << n - ans << endl;
	}

	return 0;
}


