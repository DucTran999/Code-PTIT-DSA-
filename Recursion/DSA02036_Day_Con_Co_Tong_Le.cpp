#include<bits/stdc++.h>
using namespace std;

int A[25];
int n;
vector<vector<int>> ans;
vector<int> v;

void inp() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	sort(A + 1, A + n + 1, greater<int>());
}

void in() {
	sort(ans.begin(), ans.end());
	for(auto tmp : ans) {
		for(int it : tmp)
			cout << it << " ";
		cout << endl;
	}
	ans.clear();
}

void Try(int i, int sum) {
	if(sum&1) ans.push_back(v);
	if (i > n) return;
	for(int j = i; j <= n; j++) {
		v.push_back(A[j]);
		Try(j+1, sum + A[j]);
		v.pop_back();
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		Try(1,0);
		in();
	}
	return 0;
}

