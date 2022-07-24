#include<bits/stdc++.h>
using namespace std;

int n, k;
int A[41];
set<int> setA;

bool isLast;

void inp() {
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> A[i];
		setA.insert(A[i]);
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

int countNew() {
	for(int i = 1; i <= k; i++) {
		setA.insert(A[i]);
	}
	int cnt = setA.size() - k;
	return cnt;
}

void in() {
	if(isLast) {
		cout << k << endl;
	} else {
		cout << countNew() << endl;
	}
	setA.clear();
	isLast = false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		inp();
		next_Com();
		in();
	}
}
