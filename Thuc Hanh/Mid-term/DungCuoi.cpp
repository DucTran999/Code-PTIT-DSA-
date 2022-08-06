/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int n;
string A[100];

int main() {
	sync();
	int t = 1;
	string end="";
//	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i<=n; i++) cin >> A[i];
		cin >> end;
		sort(A+1, A+n+1);
		do {
			if(A[n] == end) {
				for(int i = 1; i<=n; i++) {
					cout << A[i] << " ";
				}
				cout << endl;
			}
		} while(next_permutation(A+1, A+n+1));
	}

	return 0;
}


