#include<bits/stdc++.h>
using namespace std;

int n;
int minStep = INT_MAX;

void inp() {
	cin >> n;
	minStep = INT_MAX;
}

void Try(int i, int Step = 0) {
	if(i == 1) {
		minStep = min(Step, minStep);
		return;
	}
	if(i % 3 == 0 && Step < minStep) {
		Try(i/3, Step + 1);
	}
	if(i%2 == 0 && Step < minStep) {
		Try(i/2, Step+1);
	}
	if(i != 1 && Step < minStep) {
		Try(--i, Step+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		inp();
		Try(n);
		cout << minStep << endl;
	}
	return 0;
}

