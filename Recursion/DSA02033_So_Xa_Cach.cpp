#include<bits/stdc++.h>
using namespace std;

int n;
int A[15];
bool f[100];

void in() {
	for(int i = 1; i<=n; i++) {
		cout << A [i];
	}
	cout << endl;
}
bool check() {
	for(int i = 2; i < n ; i++) {
		if(abs(A[i] - A[i-1]) == 1 || abs(A[i] - A[i+1]) == 1)
			return false;
	}
	return true;
}

void Try(int i) {
	int j;
	for(j = 1; j <= n; j++) {
		if(f[j] == false) {
			A[i] = j;
			f[j]= true;
			if(i == n) {
				if(check() ) {
					in();
				}
			} else
				Try(i+1);
			//backtrack
			f[j] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		Try(1);
	}
	return 0;
}

