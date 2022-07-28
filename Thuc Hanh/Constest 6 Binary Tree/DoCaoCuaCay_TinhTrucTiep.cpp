#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

const int maxn = 1e5+5;

int main() {
	sync();
	int t = 1, n, x, y;
	cin >> t;
	while(t--) {
		int A[maxn];
		int height = 0;
		cin >> n;
		for(int i = 1; i < n; i++) {
			cin >> x >> y;
			A[y] = A[x] + 1;
			if(A[y] > height) height = A[y];
		}
		cout << height << endl;
	}

	return 0;
}


