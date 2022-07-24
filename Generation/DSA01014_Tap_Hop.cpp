#include<bits/stdc++.h>
using namespace std;

int n, k, s;
int A[41];
bool isLast;

void inp() {
	for(int i = 1; i <= n; i++) {
		A[i] = i;
	}
}

void next_Com() {
	int i = k;
	while(i > 0 && A[i] == n - k + i) i--;
	if( i== 0) {
		isLast = true;
	} else {
		A[i]++;
		for(int j = i + 1; j <= k; j++) {
			A[j] = A[j-1] + 1;
		}
	}
}

bool check() {
	int sum = 0;
	for(int i = 1; i <= k; i++) {
		sum+=A[i];
		if(sum > s)
			return false;
	}
	return sum == s;
}

int main() {
	while(true) {
		cin >> n >> k >> s;
		if(n == 0 && k== 0 && s == 0) {
			break;
		}
		if(n < k ) {
			cout << 0 << endl;
		} else {
			inp();
			int cnt = 0;
			while(!isLast) {
				if(check())
					cnt++;
				next_Com();
			}
			cout << cnt << endl;
			isLast = false;
			memset(A, 0, sizeof(A));
		}
	}
}
