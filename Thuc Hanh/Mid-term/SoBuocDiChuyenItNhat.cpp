/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int N, M;
int C[1001][1001], A[1001][1001];

void solve() {
	int i, j, x;
	memset(C, -1, sizeof(C));
	queue<pair<int, int>> Q;
	Q.push({1,1});
	C[1][1] = 0;
	while(!Q.empty()) {
		pair<int, int> t= Q.front();
		i = t.first;
		j = t.second;
		x = A[i][j];
		Q.pop();
		if(C[i][j+x] == -1) {
			Q.push({i, j+x});
			C[i][j+x] = C[i][j] + 1;
		}
		if(C[i+x][j] == -1) {
			Q.push({i+x,j});
			C[i+x][j] = C[i][j] + 1;
		}
		if(C[i][j] == -1) {
			Q.push({i+x,j+x});
			C[i+x][j+x] = C[i][j]+1;
		}
		if(C[N][M] != -1) break;
	}
	cout << C[N][M] << endl;
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		cin >> N >> M;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j ++) {
				cin >> A[i][j];
			}
		}
		solve();
	}

	return 0;
}


