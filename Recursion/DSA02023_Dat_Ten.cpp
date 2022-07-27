#include<bits/stdc++.h>
using namespace std;

int n, k;
int A[25];
set<string> setA;
vector<string> v;
int m;

void inp() {
	cin >> n >> k;
	cin.ignore();
	int l = n;
	while(l--) {
		string tmp;
		cin >> tmp;
		cin.ignore();
		setA.insert(tmp);
	}
	for(string s : setA) {
		v.push_back(s);
	}
	m = v.size();
}

void in() {
	for(int i = 1; i<=k; i++) {
		cout << v[A[i]-1] << " ";
	}
	cout << endl;
}

void Try(int i) {
	int j;
	for(int j = A[i-1]+ 1; j <= m; j++) {
		A[i] = j;
		if(i == k) {
			in();
		} else {
			Try(i + 1);
		}
	}
}

int main() {
	inp();
	Try(1);
	return 0;
}

