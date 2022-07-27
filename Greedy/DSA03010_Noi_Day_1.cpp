#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
long long solve(priority_queue<int, vector<int>, greater<int>> pq) {
	long long ans = 0;
	while(pq.size() > 1) {
		long long f = pq.top();
		pq.pop();
		f += pq.top();
		pq.pop();
		ans += f;
		pq.push(f);
	}
	return ans;
}

int main() {
	boost
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> pq;
		int tmp;
		while(n--) {
			cin >> tmp;
			pq.push(tmp);
		}
		cout << solve(pq) << endl;
	}

	return 0;
}

