#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int t = 1, x;
	cin >> t;
	vector<vector<int>> a(t + 1, vi(t + 1, 0));
	cin.ignore();
	string s;
	for(int i = 1; i <= t; ++i) {
		getline(cin, s);
		stringstream ss(s);
		while(ss >> s) {
			x = stoi(s);
			a[x][i] = a[i][x] = 1;
		}
	}

	for(int i = 1; i <= t; i++) {
		for(int j = 1; j <= t; j++) cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
