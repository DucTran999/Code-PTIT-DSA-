#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(string s, int k) {
	int freq[30] = {0};
	for(int i = 0; i< s.length(); i++) {
		++freq[s[i]-'A'];
	}

	priority_queue<int> pq;

	for(int i = 0; i < 26; i++) {
		if(freq[i] != 0) {
			pq.push(freq[i]);
		}
	}

	while(k) {
		ll tmp = pq.top()-1;
		pq.pop();
		pq.push(tmp);
		k--;
	}

	ll ans = 0;
	while(!pq.empty()) {
		ans += pow(pq.top(),2);
		pq.pop();
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int k;
		string s;
		cin >> k >> s;
		if(k >= s.length()) {
			cout << 0 << endl;
		} else {
			solve(s, k);
		}
	}
	return 0;
}

