/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

ll doCalc(ll a,ll b, string op) {
	if(op == "+") return a+b;
	if(op == "-") return a-b;
	if(op == "*") return a*b;
	if(op == "/") return a/b;
}

ll calc(string *A, int n) {
	stack<ll> st;
	for(int i = 0; i< n; i++) {
		if(A[i] == "+" or A[i] == "-" or A[i] == "*" or A[i] == "/") {
			ll b = st.top();
			st.pop();
			ll a = st.top();
			st.pop();
			ll res = doCalc(a, b, A[i]);
			st.push(res);
		} else {
			st.push(stoll(A[i]));
		}
	}
	return st.top();
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		string A[n];
		for(string &i : A) cin >> i;
		cout << calc(A, n) << endl;
	}

	return 0;
}


