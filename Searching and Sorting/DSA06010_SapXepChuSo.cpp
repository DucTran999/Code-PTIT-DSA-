#include<bits/stdc++.h>
using namespace std;

void solve(string s) {
	vector<int> A;
	for(char i : s) {
		A.push_back(i - '0');
	}
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(),A.end()), A.end());
	for(int i : A) cout << i << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	int t = 1, n;
	cin >> t;
	cin.ignore();
	while(t--) {
		cin >> n;
		string s="", tmp ="";
		while(n--) {
			cin >> tmp;
			s+=tmp;
		}
		solve(s);
	}
	return 0;
}

