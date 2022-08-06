/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vector<string> init;

void genAll() {
	queue<string> q;
	string tmp = "2357";
	q.push(tmp);
	while(tmp.size() < 10) {
		tmp = q.front(); q.pop();
		init.push_back(tmp);
		q.push(tmp+"2");
		q.push(tmp+"3");
		q.push(tmp+"5");
		q.push(tmp+"7");
	}
}

int main() {
	sync();
	int t = 1, n;
	genAll();
//	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 4; i<= n; i++) {
			for(int j = 0; j < init.size(); j++) {
				if(init[j].size() == i) {
					do {
						if(init[j][i-1] != '2') cout << init[j] <<endl;
					} while(next_permutation(init[j].begin(),init[j].end()));
				}
			}
		}
	}

	return 0;
}


