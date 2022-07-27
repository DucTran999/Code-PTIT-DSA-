#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int n, m, x;
	cin >> n;
	m = n;
	set<int> s;
	vector<vector<int>> ans;
	for(int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
		vector<int> v;
		for(int i : s) v.push_back(i);
		ans.push_back(v);
	}

	for(int i = ans.size(); i; i--) {
		cout << "Buoc " << i - 1 << ": ";
		for(int j : ans[i - 1]) cout << j << ' ';
		cout << endl;
	}

	return 0;
}


