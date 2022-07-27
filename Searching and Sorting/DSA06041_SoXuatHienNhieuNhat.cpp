#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

int main() {
	sync();
	int t = 1, n, k;
	cin >> t;
	while(t--) {
		cin >> n;
		int a[n], idx = 0;
		int freq[1000005] = {};
		for(int i = 0; i < n; ++i) {
			cin >> k;
			if(!freq[k]) a[idx++] = k;
			freq[k]++;
		}
		n/=2;
		int ans = -1, num;
		for(int i = 0; i < idx; ++i) {
			if(freq[a[i]] > n and freq[a[i]] > ans) {
				ans = freq[a[i]];
				num = a[i];
			}
		}
		if(ans == -1) cout << "NO\n";
		else cout << num << endl;
	}
	return 0;
}


