#include<bits/stdc++.h>
using namespace std;

int n;
int A[100];
vector<vector<int>> v;

void in() {
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); i++) {
		cout <<"(";
		for(int j = 0; j <= v[i].size() - 1; j++)
			cout << v[i][j] << " ";
		cout << v[i][v[i].size()-1] << ") ";
	}
	cout << endl;
}

void Try(int i, int k, int sum, int n) {
	for(int j=k; j >=1; j--) {
		if(sum + j <= n) {
			A[i] = j;
			if(sum + j == n) {
				vector<int> tmp(A+1, A+i+1);
				v.push_back(tmp);
			} else {
				Try(i+1,j,sum+j,n);
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		v.clear();
		cin >> n;
		Try(1, n, 0, n);
		in();
	}
	return 0;
}

