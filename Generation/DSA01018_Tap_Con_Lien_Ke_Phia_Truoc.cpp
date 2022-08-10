/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int A[25], n, k;

void prev_Com() {
	int i = k;
	while(i > 0 and A[i] == A[i-1] + 1) --i;
	if(i == 0) {
		for(int j = 1; j <= k; j++) cout << n - k + j << " ";
	} else {
		A[i]--;
		if(A[k] != n) for(int j = i + 1; j<=k; j++) A[j]++;
		for(int j = 1; j <= k; j++) cout << A[j] << " ";
	}
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		rs(A); cin >> n >> k;
		for(int i = 1; i<=k; i++) cin >> A[i];
		prev_Com();
		cout << endl;
	}

	return 0;
}


