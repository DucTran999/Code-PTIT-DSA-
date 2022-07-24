#include<bits/stdc++.h>
using namespace std;

int A[100];
int B[100];
int n, k;
vector<string> ans;

void inp() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
	}
}

bool check() {
	for(int i =1; i < k; i++) {
		if(A[B[i]] > A[B[i+1]]) {
			return false;
		}
	}
	return true;
}

void add() {
	string tmp;
	for(int i =1; i <= k; i++) {
		tmp += to_string(A[B[i]]) + " ";
	}
	ans.push_back(tmp);
}

void Try(int i) {
	int j;
	for(j = B[i-1] + 1; j <= n - k + i; j++) {
		B[i] = j;
		if(i == k) {
			if(check()) {
				add();
			}
		} else Try(i+1);
	}
}

void in() {
	sort(ans.begin(), ans.end());
	for(auto tmp : ans) {
		cout << tmp << endl;
	}
	ans.clear();
}

int main() {
	inp();
	for(int i = 2; i<=n; i++) {
		k = i;
		memset(B,0,sizeof(B));
		Try(1);
	}
	in();
	return 0;
}
