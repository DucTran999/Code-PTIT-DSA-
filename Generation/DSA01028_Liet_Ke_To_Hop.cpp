#include<bits/stdc++.h>
using namespace std;

int A[21];
int n, k;
vector<int> v;
set<int> setA;
int m;

void init() {
	for(int i = 1; i<=k; i++) {
		A[i] = i;
	}
}

void inp() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
		setA.insert(A[i]);
	}
	for(set<int>::iterator it = setA.begin(); it != setA.end(); it++) {
		v.push_back(*it);
	}
	init();
}



void in() {
	for(int i = 1; i<=k; i++) {
		cout << v[A[i]-1] <<" ";
	}
	cout << endl;
}

void Try(int i) {
	int j;
	for(j = A[i-1]+1; j <=m; j++) {
		A[i] = j;
		if(i == k)in();
		else Try(i+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inp();
	m = v.size();
	Try(1);

	return 0;
}
