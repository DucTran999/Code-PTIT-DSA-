#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
	int t;
	cin >> t;
	ll n, X;
	while(t--) {
		cin >> n >> X;
		vector<int> A(n);
		for(int i = 0; i<n; i++) {
			cin >> A[i];
		}
		int ind = lower_bound(A.begin(), A.end(), X) - A.begin();
		if(A[ind] != X) {
			ind--;
		}
		if(ind > 0) {
			ind++;
		} else {
			ind = -1;
		}
		cout << ind << endl;
	}

	return 0;
}

