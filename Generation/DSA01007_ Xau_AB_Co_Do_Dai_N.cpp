#include<bits/stdc++.h>
using namespace std;

int A[100];
int n, k;

void inp() {
	cin >> n;
	for(int i = 1; i <=n; i++) {
		A[i] = 0;
	}
}

void in() {
	for(int i = 1; i <=n; i++) {
		if( A[i] == 0)
			cout << 'A';
		else cout << 'B';
	}
	cout << " ";
}

void Try(int i) {
	int j;
	for(j = 0; j <= 1; j++) {
		A[i] = j;
		if(i == n) in();
		else Try(i+1);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>> t;
	while(t--) {
		inp();
		Try(1);
		cout << endl;
		memset(A, 0, sizeof(A));
	}

	return 0;
}



