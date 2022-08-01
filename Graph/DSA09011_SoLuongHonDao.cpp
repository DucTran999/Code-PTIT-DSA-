#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;
vector<vector<int>> a(505, vector<int>(505));

bool check(int x, int y) {
	return (x and y and x <= n and y <= m and a[x][y]);
}

void DFS(int x, int y) {
	if(check(x, y)) {
		a[x][y] = 0;
		for(int i = 0; i < 8; ++i)
			DFS(x + dx[i], y + dy[i]);
	}
}

int main() {
	sync();
	int t = 1, ans;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				cin >> a[i][j];
		ans = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(a[i][j]) {
					++ans;
					DFS(i, j);
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}


