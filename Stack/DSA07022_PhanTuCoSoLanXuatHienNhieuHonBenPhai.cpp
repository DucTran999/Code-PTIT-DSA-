#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		unordered_map<int, int> freq;
		for(int &i : a) {
			cin >> i;
			freq[i]++;
		}
		stack<int> st;
		int res[n];
		res[n - 1] = -1;
		st.push(n - 1);
		for(int i = n - 2; ~i; --i) {
			if(st.size() and freq[a[i]] < freq[a[st.top()]]) {
				res[i] = a[st.top()];
				st.push(i);
			} else {
				while(st.size() and freq[a[i]] >= freq[a[st.top()]]) st.pop();
				if(st.size()) res[i] = a[st.top()];
				else res[i] = -1;
				st.push(i);
			}
		}
		for(int i : res) cout << i << ' ';
		cout << endl;
	}
	return 0;
}
