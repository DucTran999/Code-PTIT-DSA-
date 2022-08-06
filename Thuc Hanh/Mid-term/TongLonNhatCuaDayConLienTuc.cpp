/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

ll calc(int *A, int n) {
	stack<ll> st;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		st.push(A[i]);
		for(int j = i; j < n; j++) {
			if(st.top() < A[j]) {
				st.pop(); st.push(A[j]);
			}
			ans += st.top();
		}
		st.pop();
	}
	return ans;
}

int main() {
	sync();
	int t = 1,n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int &i : A) cin >> i;
		cout << calc(A, n) << endl;
	}

	return 0;
}


