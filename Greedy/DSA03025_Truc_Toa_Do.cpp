#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> & b) {
	return a.second < b.second;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> p(n);
		for(int i = 0; i < n; i++) {
			cin >> p[i].first >> p[i].second;
		}
		sort(p.begin(), p.end(),cmp);
		int cnt = 1;
		int pre = p[0].second;
		for(int i = 1; i < n;i++){
			if(p[i].first >= pre){
				cnt++;
				pre = p[i].second;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

