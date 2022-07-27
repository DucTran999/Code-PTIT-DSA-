#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

int main() {
	sync();
	int t = 1, n, k, x;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n], f[n], sum = 0;
		cin >> A[0];
		f[0] = A[0];
		sum += A[0];

		for(int i = 1; i < n; ++i) {
			cin >> A[i];
			f[i] = f[i - 1] + A[i];
			sum += A[i];
		}

		bool check = 1;
		for(int i = 1; i < n; ++i) {
			if(f[i] - A[i] == sum - f[i]) {
				cout << i + 1 << endl;
				check = 0;
				break;
			}
		}
		if(check) cout << -1 << endl;
	}

	return 0;
}


