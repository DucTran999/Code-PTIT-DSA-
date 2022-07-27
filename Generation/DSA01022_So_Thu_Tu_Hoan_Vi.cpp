#include<bits/stdc++.h>
using namespace std;

int n;
int A[100];

void inp() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> A[i];
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>> t;
	while(t--) {
		inp();
		int count = 1;

		while(prev_permutation(A,A+n)) {
			count++;
		}
		cout << count << endl;
	}

	return 0;
}



