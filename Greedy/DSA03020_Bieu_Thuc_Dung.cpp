#include<bits/stdc++.h>
using namespace std;

long count(string s) {
	int check = 0;
	int l = 0;
	int r= 0;
	int ans = 0;
	for(int i  = 0; i < s.length(); i++) {
		if(s[i] == '[') {
			l++;
			if(check > 0) {
				ans+= check;
				check--;
			}
		} else if(s[i] == ']') {
			r++;
			check = (r - l);
		}
	}
	return ans;
}

int main() {

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << count(s) << endl;
	}

	return 0;
}

