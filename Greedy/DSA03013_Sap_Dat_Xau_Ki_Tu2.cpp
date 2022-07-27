#include<bits/stdc++.h>
using namespace std;
string s;
int D;
int freq[26];

void inp() {
	cin >> D;
	cin >> s;
	memset(freq,0, sizeof(freq));
}

void solve() {
	int maxFreq = INT_MIN;
	for(int i = 0; i < s.length(); i++) {
		++freq[s[i]-'A'];
		maxFreq = max(maxFreq, freq[s[i]-'A']);
	}
	int slot = (D-1)*(maxFreq-1);
	if(maxFreq + slot <= s.length()) {
		cout << 1 << endl;
	} else {
		cout << -1 << endl;
	}
}

int main() {
	int t;
	cin>> t;
	while(t--) {
		inp();
		solve();
	}
	return 0;
}

