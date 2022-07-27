#include<bits/stdc++.h>
using namespace std;

int A[1000];
int B[1000];

int n, k;
bool isLast;

void inp() {
	cin >> n >> k;
	for(int i = 1; i <= k; i++) {
		cin >> A[i];
		B[i] = A[i];
	}
}

void next_Combination() {
	int i = k;
	while(i > 0 && A[i] == n - k + i) {
		--i;
	}
	if(i == 0) {
		isLast = true;
	} else {
		A[i]++;
		for(int j = i + 1; j <= k; j++) {
			A[j] = A[j-1] + 1;
		}
	}

}

int diff() {
	int ans = 0;
	for(int i = 1 ; i <= k; i++) {
		int tmp = 0;
		for(int j = 1 ; j <= k; j++) {
			if(B[j] != A[i]) {
				tmp++;
			} else break;
		}
		if(tmp == k) {
			ans++;
		}
	}
	return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		next_Combination();
		if(!isLast) {
			cout << diff() << endl;
		} else {
			cout << k << endl;
		}
		isLast = false;
	}
	return 0;
}


