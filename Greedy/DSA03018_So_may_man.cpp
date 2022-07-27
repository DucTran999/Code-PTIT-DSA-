#include<bits/stdc++.h>
using namespace std;

void solve(int n) {
	int cnt7 = 0;
	int cnt4 = 0;
	while(n > 0) {
		if(n%7==0) {
			cnt7++;
			n-=7;
		} else if(n%4 == 0) {
			cnt4++;
			n-=4;
		} else {
			cnt7++;
			n-=7;
		}
	}
	if(n < 0) {
		cout << -1 << endl;
	} else {
		while(cnt4--) cout << 4;
		while(cnt7--) cout << 7;
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		solve(n);
	}
	return 0;
}

