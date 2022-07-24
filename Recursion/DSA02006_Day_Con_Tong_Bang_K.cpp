#include<bits/stdc++.h>
using namespace std;

int n, k;
int A[25];
int I[25];
int ok = 0;
vector<vector<int>> v;

void inp() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	v.clear();
	ok = 0;
	sort(A+1, A+n+1);
}

void add() {
	int sum = 0;
	vector<int> tmp;
	for(int i = 1; i <= n; i++) {
		if(sum > k) {
			break;
		}
		if(I[i] != 0) {
			tmp.push_back(A[i]);
		}
		sum+= A[i] * I[i];
	}
	if(sum == k) {
		ok = 1;
		v.push_back(tmp);
	}
}

void in() {
	for(int i = 0; i < v.size(); i++) {
		cout << "[";
		for(int j = 0; j < v[i].size() - 1; j++) {
			cout << v[i][j] << " ";
		}
		cout <<v[i][v[i].size()-1] << "] ";
	}

	cout << endl;
}

void Try(int i) {
	for(int j = 1; j >= 0; j--) {
		I[i] = j;
		if(i == n) {
			add();
		} else Try(i+1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		Try(1);
		if(ok == 1) {
			in();
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}

