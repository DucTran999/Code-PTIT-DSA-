#include<bits/stdc++.h>
using namespace std;

int n, X;
int A[25];
vector<vector<int>> v;
vector<int> ans;
int ok = 0;

void inp() {
	cin >> n >> X;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	v.clear();
	ok = 0;
}

void Try(int i, int target) {
	if(i == n + 1) {
		if(target == 0) {
			ok = 1;
			v.push_back(ans);
		}
		return;
	}
	if(A[i] <= target) {
		ans.push_back(A[i]);
		Try(i, target - A[i]);
		ans.pop_back();
	}
	Try(i+1, target);
}

void in() {
	if(ok == 0) {
		cout << -1 << endl;
	} else {
		cout << v.size() << " ";
		for(int i = 0; i < v.size(); i++) {
			cout <<"{";
			for(int j = 0; j < v[i].size() - 1; j++) {
				cout << v[i][j] << " ";
			}
			cout << v[i][v[i].size()-1] << "} ";
		}
		cout << endl;
	}
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		inp();
		Try(1,X);
		in();
	}

	return 0;
}

