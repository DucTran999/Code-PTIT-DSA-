#include<bits/stdc++.h>
using namespace std;

int A[40];
int n, total;
int minStep = INT_MAX;
int ok = 0;

inline int min(int a, int b) {
	return (a < b) ? a : b;
}

void inp() {
	cin >> n >> total;
	for(int i = 1 ; i <= n; i++) {
		cin >> A[i];
	}
	sort(A+1, A+n+1);
}

int filter() {
	for(int i = 1; i<=n; i++) {
		if(A[i] > total) {
			continue;
		} else {
			return i;
		}
	}
}

void Try(int i, int total, int stop, int step) {
	if(total == 0) {
		ok = 1;
		minStep = min(minStep, step);
		return;
	}
	if (i < stop) return;
	for(int j = i; j >= stop; j--) {
		if(total >= A[j] && step < minStep) {
			Try(j-1, total - A[j], stop, step+1);
		}
	}
}

bool preprocess() {
	int sum = 0;
	for(int i = 1; i <= n ; i++) {
		sum += A[i];
	}
	if(sum < total) {
		return false;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		inp();
		if(!preprocess()) {
			cout << -1;
		} else {
			int st = filter();
			Try(n,total,st,0);
			if(ok == 1) {
				cout << minStep;
			} else {
				cout << -1;
			}
		}
		ok = 0;
		cout << endl;
	}

	return 0;
}

