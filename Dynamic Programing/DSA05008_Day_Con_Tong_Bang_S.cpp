#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	cin >> t;
	int n, S;
	while(t--) {
		cin >> n >> S;
		int A[n+1];
		int L[S+1];
		for(int i = 1; i<=n; i++) {
			cin >> A[i];
		}
		memset(L, 0, sizeof(L));
		L[0] = 1;
		for(int i = 1; i <= n; i++) {
			for(int j = S; j >= A[i]; j--) {
				if(L[j] == 0 &&  L[j - A[i]] == 1)
					L[j] = 1;
			}
		}
		if(L[S]) cout << "YES\n";
		else cout << "NO\n";	
	}
	return 0;
}

