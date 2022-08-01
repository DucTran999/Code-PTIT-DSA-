#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
#define sync(); ios_base::sync_with_stdio(0);

void solve(ll *a, ll *b, ll *c, int x, int y , int z){
	int idxA, idxB, idxC;
		idxA = idxB = idxC = 0;
		multiset<ll> ans;
		while(idxA < x && idxB < y && idxC < z) {
			if(a[idxA] == b[idxB] && b[idxB] == c[idxC]) {
				ans.insert(a[idxA]);
				++idxA;
				++idxB;
				++idxC;
			} else if(a[idxA] < b[idxB]) ++idxA;
			else if(b[idxB] < c[idxC]) ++idxB;
			else ++idxC;
		}
		if(ans.empty()) cout << -1;
		else for(ll i : ans) cout << i << ' ';
		cout << endl;
}

int main() {
	sync();
	int t = 1, x, y, z, a;
	cin >> t;
	while(t--) {
		cin >> x >> y >> z;
		ll a[x], b[y], c[z];
		for(int i = 0; i < x; i++) cin >> a[i];
		for(int i = 0; i < y; i++) cin >> b[i];
		for(int i = 0; i < z; i++) cin >> c[i];
		solve(a, b, c, x, y , z);
	}

	return 0;
}

