/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int main(){
	sync();
	int t = 1, n;
	cin >> t;
	while(t--){
		cin >> n;
		int A[n];
		for(int &i : A) cin >> i;
		int cnt = 0;
		do{
			cnt++;
		}while(prev_permutation(A, A+n));
		cout << cnt << endl;
	}
	
	return 0;
}


