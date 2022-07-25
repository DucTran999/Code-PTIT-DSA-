#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int t = 1, n;
	cin >> n;
	vi v(n);
	for(int &i : v) cin >> i;
	int m = n - 1;
	for(int i = 0; i < m; i++) {
		cout << "Buoc " << i + 1 << ": ";
		for(int j = i + 1; j < n; j++ )
			if(v[i] > v[j]) swap(v[i], v[j]);
		for(int i : v) cout << i << ' ';
		cout << endl;
	}

	return 0;
}


