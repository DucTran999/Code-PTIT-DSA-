#include <bits/stdc++.h>
using namespace std;

int isPrime[101];
vector<int> factor;
long long ans;
int n;

void sieve() {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2; i*i <= 100; i++) {
		if(isPrime[i]) {
			for(int j = i*i; j <= 100; j+=i) {
				isPrime[j] = 0;
			}
		}
	}
	for(int i = 2; i <= 100; i++) {
		if(isPrime[i])
			factor.push_back(i);
	}
}

void Try(int i, int soUoc, long long res) {
	if(soUoc > n) return;
	if(soUoc == n)
		ans = min(res, ans);
	for(int j = 1; j < n; j++) {
		if(res*factor[i] > ans) break;
		res*=factor[i];
		Try(i+1, soUoc*(j+1), res);
	}

}


int main() {
	sieve();
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		ans = 1e18;
		Try(0, 1, 1);
		cout << ans << endl;
	}

	return 0;
}

