#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

int main(){
	sync();
	int t = 1,n,m;
	cin >> t;
	while(t--){
		cin >> n >>m;
		vi A(n),B(m),C(n+m);
		for(int &i : A) cin >> i;
		for(int &i : B) cin >> i;
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		merge(A.begin(), A.end(), B.begin(), B.end(), C.begin());
		for(int i : C) cout << i << ' ';
		cout << endl;
	}
	
	return 0;
}


