#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i<n; i++) {
			cin >> a[i];
		}
		int ind = lower_bound(a.begin(), a.end(), 1) - a.begin();
		if(ind > -1 && ind < n && a[ind] == 1) {
			cout << ind << endl;
		} else {
			cout << "0\n";
		}
	}
	return 0;
}

