#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int n, tmp;
	cin >> n;
	multiset<int> s;
	for(int i = 0; i < n; ++i) {
		cin >> tmp;
		s.insert(tmp);
		cout << "Buoc " << i << ": ";
		for(int i : s) cout << i << ' ';
		cout << endl;
	}

	return 0;
}

