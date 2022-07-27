#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);


int main() {
	sync();
	int t = 1, n, k;
	cin >> t;
	while(t--) {
		deque<int> dq;
		cin >> n >> k;
		int A[n];
		for(int &i : A) cin >> i;
		dq.push_back(0);
		for(int i = 1; i < k; ++i) {
			while(!dq.empty() and A[dq.back()] < A[i]) dq.pop_back();
			dq.push_back(i);
		}
		cout << A[dq.front()] << ' ';

		for(int i = k; i < n; ++i) {
			while(!dq.empty() && A[dq.back()] < A[i]) dq.pop_back();
			dq.push_back(i);
			if(i - dq.front() < k) cout << A[dq.front()] << ' ';
			else {
				dq.pop_front();
				cout << A[dq.front()] << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}


