#include<bits/stdc++.h>
using namespace std;

void findMax(string s, int step, string& smax) {
	if (step == 0)
		return;
	for(int i = 0; i < s.length()-1; i++) {
		for(int j = i+1; j < s.length(); j++) {
			if(s[i] < s[j]) {
				swap(s[i],s[j]);
				if(s.compare(smax) > 0) {
					smax = s;
				}
				findMax(s, step - 1, smax);
				swap(s[i],s[j]);
			}
		}
	}
}

void solve(string s, int k) {
	if(k == 0) {
		cout << s << endl;
	} else if(k >= s.length()) {
		sort(s.begin(),s.end(),greater<int>());
		cout << s << endl;
	} else {
		string smax = s;
		findMax(s, k, smax);
		cout << smax << endl;
	}

}

int main() {

	int t;
	cin >> t;
	while(t--) {
		int k;
		string s;
		cin >> k >> s;
		solve(s, k);
	}

	return 0;
}

