#include<bits/stdc++.h>
using namespace std;

void solve(int S, int D) {
	int ans[D];
	if(S == 0 && D != 0) {
		cout << -1 << endl;
		return;
	}
	if(S > D*9) {
		cout << -1 << endl;
		return;
	}

	S--;
	ans[0] = 1;
	for(int i = D-1; i >=1; i--) {
		if(S > 9) {
			S-=9;
			ans[i] = 9;
		} else {
			ans[i] = S;
			S = 0;
		}
	}
	if(S!=0) {
		ans[0]+=S;
	}
	for(int i = 0; i < D; i++) {
		cout << ans[i];
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int S, D;
		cin >> S >> D;
		solve(S,D);
	}
	return 0;
}

