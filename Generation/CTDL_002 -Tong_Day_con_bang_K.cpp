#include<bits/stdc++.h>
using namespace std;

int A[100];
int n, k;
int bin[100];
vector<vector<int>> v;

void inp() {
	for(int i = 1; i<=n; i++) {
		cin >> A[i];
	}
	sort(A+1, A+n+1);
}

void in() {
	for(int i = v.size()-1; i>-1; i--) {
		for(int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << v.size() << endl;
}

void check() {
	int sum = 0;
	vector<int> tmp;
	for(int i = 1; i <= n; i++) {
		sum+= A[i]*bin[i];
		if(bin[i]!=0) {
			tmp.push_back(A[i]);
		}
	}
	if(sum == k) v.push_back(tmp);
}

void Try(int i) {
	int j;
	for(j = 1; j >=0; j--) {
		bin[i]= j;
		if(i == n)check();
		else Try(i+1);
	}
}

int main() {
	cin >> n >> k;
	inp();
	memset(bin, 1, sizeof(bin));
	Try(1);
	in();
}


