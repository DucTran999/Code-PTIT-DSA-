#include<bits/stdc++.h>
using namespace std;

int A[1000];
int n, k;
bool isFirst;

void inp() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> A[i];
	}
}

void prev_Com() {
	int i = k;
	while(i >= 1 && A[i] == A[i-1] + 1) {
		i--;
	}
	if(i == 0 && A[i+1] == 1) {
		isFirst = true;
	} else {
		A[i]--;
		if(A[k] != n) {5
		
			for(int j = i+1; j<=k; j++) {
				A[j] = A [j] + 1;
			}
		}
	}
}

void in() {
	if(isFirst) {
		for (int i = 1; i <= k; i++) {
			cout << n - k + i<<" ";
		}
		cout << endl;
	} else {
		for (int i = 1; i <= k; i++)
			cout << A[i] << " ";
		cout << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		inp();
		prev_Com();
		in();
		isFirst = false;
	}
}
