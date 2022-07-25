#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int t = 1, n, k, x;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		unordered_map<ll, ll> freq;
		vll v(n);
		ll cnt = 0;
		for(ll &i : v) {
			cin >> i;
			freq[i]++;
		}

		if((k & 1) ^ 1 and freq[k/2]) {
			cnt += freq[k/2] * (freq[k/2] - 1) / 2;
			freq[k/2] = 0;
		}
		
		for(ll i : v) {
			if(freq[i]) {
				cnt += freq[i] * freq[k - i];
				freq[i] = freq[k - i] = 0;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

