#include<bits/stdc++.h>
using namespace std;

bool check(int n, vector<int> &v) {
	for(int i = 0; i < v.size(); i++) {
		if(v[i] / n == v[i] / (n + 1))
			return 0;
	}
	return 1;
}

int main() {

	int n;
	cin >> n;
	vector<int> A(n), B(n), C(n);
	for(int i = 0; i < A.size(); i++)
		cin >> A[i];
	B = C = A ;
	sort(B.begin(), B.end());

	for(int i = B[0]; i >= 0; i--) {
		if(check(i, A)) {
			for(int j = 0; j < n; j++) {
				C[j] = A[j] / (i + 1) + 1;
			}
			break;
		}
	}

	int ans = 0;
	for(int i = 0; i < C.size(); i++)
		ans += C[i];
	cout << ans << endl;

	return 0;
}
