#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a, ans;

void solve() {

	cin >> n;
	int x;
	for(int i = 0; i<n ; i++) {
		cin >> x;
		a.push_back(x);
	}
	cout << "[";
	for(int i = 0; i < n - 1; i++) {
		cout << a[i] << " ";
	}
	cout << a[n-1] << "]" << endl;

	while(n > 1) {
		for(int i = 0; i < n-1; i++) {
			ans.push_back(a[i] + a[i+1]);
		}
		cout << "[";
		for(int i = 0; i < ans.size() - 1; i++) {
			cout << ans[i] << " ";
		}
		cout << ans[ans.size()-1] << "]"<< endl;
		a = ans;
		ans.clear();
		n--;
	}
	
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		a.clear();
		solve();
	}
	return 0;
}
