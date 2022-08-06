/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int n, k, A[100];

void Try(int i) {
	for(int j = n - k + i; j >= A[i-1]+1; j--) {
		A[i] = j;
		if(i == k) {
			for(int x = 1; x <= k ; x++) cout << A[x] << " ";
			cout << endl;
		} else Try(i+1);
	}
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		rs(A);
		cin >> n >> k;
		Try(1);
	}

	return 0;
}


