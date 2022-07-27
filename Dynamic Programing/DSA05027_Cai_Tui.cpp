#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n = 0, L=0;
		cin >> n >> L;
		int W[n+1];
		int V[n+1];
		int C[n+5][L+5];
		memset(C,0 ,sizeof(C));
		for(int i = 1; i <= n; i++) cin >> W[i];
		for(int i = 1; i <= n; i++) cin >> V[i];

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= L; j++) {
				//khong lua chon do thu j vao tui
				
				// Co the them do vat i vao
				if(j >= W[i]) {
					C[i][j] = max(C[i][j], C[i-1][j-W[i]] + V[i]);
				}else C[i][j] = C[i-1][j];
			}
		}
		cout <<  C[n][L] << endl;
	}

	return 0;
}

