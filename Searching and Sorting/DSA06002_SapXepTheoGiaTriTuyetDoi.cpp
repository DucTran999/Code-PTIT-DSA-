#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	int t = 1, n, k;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		vector<pair<int, int>> v(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i].first;
			v[i].second = abs(v[i].first - k);
		}
		stable_sort(v.begin(), v.end(), comp);
		for(int i = 0; i < n; i++) cout << v[i].first << " ";
		cout << endl;
	}
	return 0;
}

