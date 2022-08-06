/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

struct item {
	int val, wei;
};

int main() {
	sync();
	int t = 1, n, b;
//	cin >> t;
	while(t--) {
		cin >> n >> b;
		item v[n+1];
		for(int i = 1; i <= n; i++) {
			cin >> v[i].wei >> v[i].val;
		}
		int dp[n+1][b+1];
		rs(dp);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= b; j++) {
				dp[i][j] = dp[i-1][j];
				if(j >= v[i].wei) {
					dp[i][j] = max(dp[i][j], dp[i-1][j -v[i].wei] + v[i].val);
				}
			}
		}
		cout << dp[n][b] << endl;
	}

	return 0;
}


