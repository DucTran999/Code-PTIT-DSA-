#include<bits/stdc++.h>
using namespace std;

int n;
int A[25];
vector<vector<int>> v;

void inp() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
	}
}

void solve(int size) {
	if(size == 1) return;
	else {
		for(int i = 1; i < size; i++) {
			A[i] = A[i] + A[i+1];
		}
		vector<int> tmp (A+1, A+size);
		v.push_back(tmp);
		solve(size - 1);
	}
}

void in() {
	for(int i = v.size() - 1; i >= 0; i--) {
		cout << "[";
		for(int j = 0; j < v[i].size() -1; j++) {
			cout << v[i][j] << " ";
		}
		cout << v[i][v[i].size()-1] <<"] ";

	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		vector<int> tmp (A+1, A+1+n);
		v.push_back(tmp);
		solve(n);
		in();
		cout << endl;
		v.clear();
	}
	return 0;
}

