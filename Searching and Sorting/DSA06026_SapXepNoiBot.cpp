#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main() {
	sync();
	int n;
	cin >> n;
	int A[n];
	for(int &i : A) cin >> i;
	int cnt = 0;
	for(int i = 0; i < n - 1; i++) {
		bool check = 0;
		for(int j = 1; j < n; j++)
			if(A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
				check= 1;
			}
		if(!check) break;
		cout << "Buoc " << ++cnt << ": ";
		for(int i : A) cout << i << ' ';
		cout << endl;
	}

	return 0;
}


