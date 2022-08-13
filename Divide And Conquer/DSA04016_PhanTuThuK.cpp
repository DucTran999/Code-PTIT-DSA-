/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int main(){
	sync();
	int t = 1, n, m, k;
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		vi A(n), B(m), ans(n+m);
		for(int &i : A) cin >> i;
		for(int &i : B) cin >> i;
		merge(A.begin(),A.end(), B.begin(), B.end(), ans.begin());
		cout << ans[k-1] << endl;
	}
	
	return 0;
}


