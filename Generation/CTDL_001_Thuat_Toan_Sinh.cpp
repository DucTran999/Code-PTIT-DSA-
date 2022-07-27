#include<bits/stdc++.h>
using namespace std;

int A[25];
int n;

void in() {
	for(int i = 1; i <= n; i++) {
		cout << A[i] <<" ";
	}
	cout << endl;
}
bool check() {
	for(int i = 1; i <= n/2; i++) {
		if(A[i] != A[n-i+1])
			return false;
	}
	return true;
}
void Try(int i) {
	int j;
	for(j = 0; j <=1; j++) {
		A[i] = j;
		if(i == n) {
			if(check()) {
				in();
			}
		} else
			Try(i+1);
	}
}

int main() {
	cin >> n;
	Try(1);

	return 0;
}

