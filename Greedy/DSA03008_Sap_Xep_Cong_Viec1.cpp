#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int, int> &b) {
	return a.second < b.second;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >>n;
		vector<pair<int, int>> pl(n);

		for(int i = 0; i < n; i++) cin >> pl[i].first;
		for(int i = 0; i < n; i++) cin >> pl[i].second;
		sort(pl.begin(), pl.end(), cmp);

		int cnt = 1;
		int prev = pl[0].second;
		for(int i = 1; i < n; i++) {
			if(pl[i].first >= prev) {
				cnt++;
				prev = pl[i].second;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

