#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[505];

ll Calc(vector<pair<float, float>>& v) {
	int n = v.size();
	if(n == 1) return 1;
	memset(dp, 0, sizeof(dp));
	ll res = 0;
	for(int i = 0; i < n; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++) {
			if(v[j].first < v[i].first and v[j].second > v[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			res = max(res, dp[i]);
		}
	}
	return res;
}

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<pair<float, float>> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i].first >> v[i].second;
		v.erase(unique(v.begin(), v.end()), v.end());
		cout << Calc(v) << endl;
	}

	return 0;
}

