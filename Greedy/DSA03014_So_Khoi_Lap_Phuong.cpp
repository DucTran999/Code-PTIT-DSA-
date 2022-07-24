#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v;

string findCube(string &s) {
	string tmp;
	for(int i = 0; i < v.size(); i++) {
		tmp = to_string(v[i]);
		int ind = 0;
		for(char j = 0; j < s.length(); j++) {
			if(s[j] == tmp[ind]) {
				ind++;
			}
		}
		if(ind == tmp.size())
			return tmp;
	}
	return "-1";
}

int main() {
	int t = 1;
	cin >> t;
	for(int i = 100; i >= 0; --i)
		v.push_back(i * i * i);

	string s;
	while(t--) {
		cin >> s;
		cout << findCube(s) << endl;
	}
	return 0;
}
