#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

string calc(int *A, int n, unordered_map<int, int> &m) {
	for(int i = 0; i < n; ++i)
		if(m[A[i]] > 1) return to_string(A[i]);
	return "NO";
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	int n, A[100005];
	while(t--) {
		cin >> n;
		unordered_map<int, int> m;
		for(int i = 0; i < n; ++i) {
			cin >> A[i];
			++m[A[i]];
		}
		cout << calc(A, n, m) << endl;
	}
	return 0;
}

