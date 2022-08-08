/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int A[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

void demTien(int ind, int soTien) {
	int cnt = 0;
	while(soTien != 0) {
		if(soTien >= A[ind]) {
			cnt = cnt + soTien/A[ind];
			soTien%=A[ind];
		} else {
			ind--;
		}
	}
	cout << cnt << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int it =  lower_bound(A, A+10,n) - A;
		if(A[it] == n) {
			cout << 1 << endl;
		} else {
			if(it > 9) {
				it = 9;
				demTien(it, n);
			} else if(it > 0 && it < 9) {
				it--;
				demTien(it, n);
			}
		}
	}
	return 0;
}


