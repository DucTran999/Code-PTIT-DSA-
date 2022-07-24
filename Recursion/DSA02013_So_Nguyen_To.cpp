#include<bits/stdc++.h>
using namespace std;

bool notPrime[200];
int N, P, S;
vector<int> p, tmp;
vector<vector<int>> ans;

void sieve() {
	notPrime[0] = notPrime[1] = 1;
	for(int i = 2; i <= sqrt(200); i++) {
		if(!notPrime[i]) {
			for(int j = i*i; j <= 200; j+=i) {
				notPrime[j]=1;
			}
		}
	}
	for(int i = 2; i <= 200; i++) {
		if(!notPrime[i]) {
			p.push_back(i);
		}
	}
}

void Try(int i, int sum = 0) {
	if(sum > S) return;
	if(sum == S) {
		if(tmp.size() == N) ans.push_back(tmp);
		return;
	}
	for(int j = i; j < p.size(); ++j) {
		tmp.push_back(p[j]);
		Try(j + 1, sum + p[j]);
		tmp.pop_back();
	}
}

void in() {
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto tmp : ans) {
		for(int x : tmp)
			cout << x << " ";
		cout << endl;
	}

	ans.clear();
	tmp.clear();
}

int main() {
	ios_base::sync_with_stdio(0);
	sieve();
	int t;
	cin >> t;
	while(t--) {
		cin >> N >> P >> S;
		int it = upper_bound(p.begin(),p.end(), P) - p.begin();
		Try(it);
		in();
	}

	return 0;
}

