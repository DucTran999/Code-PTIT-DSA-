#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		ll n,k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int it = lower_bound(a.begin(), a.end(), k)- a.begin();
		if(it >  -1 && it < n && a[it] == k) {
			cout << it + 1<< endl;
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}

