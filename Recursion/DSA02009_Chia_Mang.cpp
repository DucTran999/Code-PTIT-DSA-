#include<bits/stdc++.h>
using namespace std;

int A[100];
int C[100];
bool B[100];
int n, k;
int subSum;
int ok;

void inp() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
	}
}

void Try(int i, int k, int sum) {
	if(ok) return;
	if(k == 1) {
		ok = 1;
		return;
	}
	if (i > n) return;
	for(int j = 1; j <=n; j++) {
		if(B[j] == false && sum < subSum) {
			B[j] = true;
			sum += A[j];
			if(sum == subSum) {
				Try(1,k-1,0);
			} else
				Try(i + 1, k, sum);
			//backtrack
			sum -= A[j];
			B[j] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		int sum = 0;
		for(int i = 1; i<=n; i++) {
			sum += A[i];
		}
		if(sum%k != 0) {
			cout << 0;
		} else {
			subSum = sum/k;
			Try(1, k,0);
			if(ok) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}

	return 0;
}

