#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int n, tmp;
	cin >> n;
	vector<vi> v(n+1);
	cin.ignore();
	string s;
	for(int i = 1; i <= n; i++) {
		getline(cin, s);
		stringstream ss(s);
		while(ss >> s) {
			tmp = stoi(s);
			v[i].push_back(tmp);
		}
	}

	for(int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
		for(int &j : v[i]) if(j > i) cout << i << ' ' << j << endl;
	}

	return 0;
}


