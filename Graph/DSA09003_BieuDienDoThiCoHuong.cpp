/* Contributed by: Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

vi List[1005];

int main() {
	sync();
	int t = 1, m, n, x, y;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		vector<set<int>> List(n + 1);
		while(m--) {
			cin >> x >> y;
			List[x].insert(y);
		}
		for(int i = 1; i <= n; ++i) {
			cout << i << ": ";
			if(List[i].empty()) continue;
			for(auto &j : List[i]) cout << j << ' ';
			cout << endl;
		}
	}

	return 0;
}


