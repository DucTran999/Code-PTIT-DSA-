#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

int main() {
	sync();
	int n;
	cin >> n;
	vector<int> A(n+1), B, C;
	for(int i = 1; i <= n; i++) {
		cin >> A[i];
		if(i&1) B.push_back(A[i]);
		else C.push_back(A[i]);
	}
	sort(B.begin(), B.end());
	sort(C.begin(), C.end(), greater<int>());
	int odd = 0, oven = 0;
	for(int i = 1; i <= n; i++) {
		if(i&1) cout << B[odd++] << " ";
		else cout << C[oven++] << " ";
	}
	cout << endl;
	return 0;
}


