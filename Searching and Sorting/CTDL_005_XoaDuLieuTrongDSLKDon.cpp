#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n;
	int A[n];
	for(int &i : A) cin >> i;
	cin >> k;
	for(int &i : A)
		if(i != k) cout << i << ' ';
	return 0;
}

