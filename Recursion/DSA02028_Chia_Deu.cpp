#include<bits/stdc++.h>
using namespace std;

int n, k;
int A[100];
int ans;
bool ok;

void Try(int i, int s,int subSum,int cnt) {
	if (cnt == k && i == n+1) {
		ans++;
		return;
	}
	for (int j = i; j <= n; j++) {
		s += A[j];
		if (s == subSum)
			Try(j+1, 0, subSum, cnt+1);
	}
}

int main() {
	cin >> n >> k;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
		sum += A[i];
	}

	if(sum%k != 0) {
		cout << 0;
	} else {
		Try(1,0,sum/k,0);
		cout << ans;
	}

	return 0;
}

