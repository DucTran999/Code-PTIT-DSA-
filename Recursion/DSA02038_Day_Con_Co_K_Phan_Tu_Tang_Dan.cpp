#include<bits/stdc++.h>
using namespace std;

int n, k;
int A[20];
int B[20];

bool check() {
	for(int i = 1; i <k; i++) {
		if(B[A[i]] > B[A[i+1]])
			return false;
	}
	return true;
}

void Try(int i) {
	int j;
	for(int j = A[i-1]+1; j <= n - k + i; j++) {
		A[i] = j;
		if(i == k) {
			if(check()) {
				for(int i = 1; i <=k; i++) {
					cout << B[A[i]] << " ";
				}
				cout << endl;
			}
		} else Try(i+1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) {
			cin >> B[i];
		}
		sort(B+1, B+1+n);
		Try(1);
	}
	return 0;
}

