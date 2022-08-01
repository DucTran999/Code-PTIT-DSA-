#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int t = 1, n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		int A[n], B[m], freq[100005];
		memset(freq, 0 , sizeof(freq));
		set<int> setA;
		for(int &i : A) {
			cin >> i;
			freq[i]++;
			setA.insert(i);
		}
		for(int &i : B) {
			cin >> i;
			freq[i]++;
			setA.insert(i);
		}
		for(int i : setA) cout << i << " ";
		cout << endl;
		for(int i : B) if(freq[i] > 1) cout << i <<" ";
		cout << endl;
	}

	return 0;
}

