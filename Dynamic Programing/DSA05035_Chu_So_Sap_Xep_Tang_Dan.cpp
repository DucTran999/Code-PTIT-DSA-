#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int M = 1e9+7;

ll Calc(int n) {
	int N = 10;
	ll count = 1;
	for (int i=1; i<=n; i++) {
		count *= (N+i-1);
		count /= i;
	}

	return count%M;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << Calc(n) << endl;
	}

	return 0;
}
