#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

struct Node {
	int data;
	Node* left, *right;
	Node(int x) {
		data = x;
		left = right = nullptr;
	}
};

void dfs(Node* root) {
	if(!root) return;
	dfs(root->left);
	dfs(root->right);
	cout << root->data << " ";
}

Node* createBST(int *A, int s, int e) {
	if(s > e) return nullptr;
	int mid = (s + e) / 2;
	Node* root = new Node(A[mid]);
	root->left = createBST(A, s, mid-1);
	root->right = createBST(A, mid+1, e);
	return root;
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int i  = 0; i < n; i++)	cin >> A[i];
		sort(A, A+n);
		Node* root = createBST(A, 0, n-1);
		dfs(root);
		cout << endl;
		root=nullptr;
		delete root;
	}

	return 0;
}


