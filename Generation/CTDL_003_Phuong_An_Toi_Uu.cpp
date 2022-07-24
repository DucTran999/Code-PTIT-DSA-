#include<bits/stdc++.h>
using namespace std;
int n, L;
int W[100], V[100];
vector<vector<int>> v;
vector<int> tmp;
int ans;

void inp() {
	cin >> n >> L;
	for(int i = 1; i <= n; i++) cin >>  V[i];
	for(int i = 1; i <= n; i++) cin >>  W[i];
}

void Try(int i, int L,int res) {
	if(L < 0) return;
	if(L >= 0 && res > ans) {
		ans = res;
		v.clear();
		v.push_back(tmp);
	}
	for(int j = i; j <= n; j++) {
		tmp.push_back(j);
		Try(j+1, L - W[j], res + V[j]);
		tmp.pop_back();
	}
}

void in() {
	int A[n] = {0};
	cout << ans << endl;
	for(auto vt : v) {
		for(int i : vt) {
			A[i] = 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
int main() {
	inp();
	Try(1,L,0);
	in();
	return 0;
}

