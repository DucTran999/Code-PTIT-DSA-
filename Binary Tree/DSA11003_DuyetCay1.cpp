#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

int search(int *A, int n, int x) {
	for(int i = 0; i < n; i++) {
		if(A[i] == x) {
			return i;
		}
	}
	return -1;
}

void postOrder(int *in,int *pre, int n) {
	int root = search(in,n,pre[0]);
	if(root != 0) {
		postOrder(in, pre + 1,root);
	}
	if(root != n - 1) {
		postOrder(in + root + 1,pre + root + 1, n - root - 1);
	}
	cout << pre[0] << " ";
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		int pre[1005], in[1005], n;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> in[i];
		}
		for(int j = 0; j < n; j++) {
			cin >> pre[j];
		}
		postOrder(in,pre,n);
		cout << endl;
	}

	return 0;
}


