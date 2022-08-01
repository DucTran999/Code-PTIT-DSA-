#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9+7;

ll solve(priority_queue<int, vector<int>, greater<int>> pq) {
	ll ans = 0;
	ll tmp = 0;
	while(pq.size() > 1) {
		tmp = pq.top()%M;
		pq.pop();
		tmp = (tmp + pq.top())%M;
		pq.pop();
		ans%=M;
		ans = (ans + tmp)%M;
		pq.push(tmp);
	}
	return ans%M;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> pq;
		while(n--) {
			int tmp;
			cin >> tmp;
			pq.push(tmp);
		}
		cout << solve(pq) << endl;
	}
	return 0;
}

