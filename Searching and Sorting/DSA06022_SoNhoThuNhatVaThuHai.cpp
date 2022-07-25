#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int &i : A) cin >> A;

		sort(A, A + n);
		if(A[0] != A[1])
			cout << A[0] << " " << A[1] << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}

