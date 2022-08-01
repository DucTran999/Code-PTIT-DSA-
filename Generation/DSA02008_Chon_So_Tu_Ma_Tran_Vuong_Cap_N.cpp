#include<bits/stdc++.h>
using namespace std;

int mt[11][11];
int n, s;
int A[11];
vector<vector<int>> v;

void inp() {
	cin >> n >> s;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> mt[i][j];
		}
	}
}

void init() {
	for(int i = 1; i <= n; i++) {
		A[i] = i;
	}
}

void check() {
	int sum = 0;
	vector<int> tmp;
	for(int i = 1; i<=n; i++) {
		if(sum > s) {
			break;
		}
		sum+=mt[i][A[i]];
		tmp.push_back(A[i]);
	}
	if(sum == s) {
		v.push_back(tmp);
	}
}

void in() {
	cout << v.size() << endl;
	for(vector<int> tmp : v) {
		for(int i : tmp) {
			cout << i << " ";
		}
		cout << endl;
	}
}

int main() {
	inp();
	init();
	do {
		check();
	} while(next_permutation(A+1, A+n+1));
	in();

	return 0;
}

