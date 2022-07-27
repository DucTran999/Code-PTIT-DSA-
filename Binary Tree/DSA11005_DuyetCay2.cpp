#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

struct Node {
	int data;
	Node* left, *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};

Node* BT(Node* root, int idx, int *A, int n) {
	if(idx < n) {
		root = new Node(A[idx]);
		root->left = BT(root->left, (idx<<1)+1, A, n);
		root->right = BT(root->right, (idx<<1)+2, A, n);
	}
	return root;
}

void PostOrder(Node* root) {
	if(root == nullptr) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data <<" ";
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int in[n], level[n];
		for(int &i : in) cin >> i;
		for(int &i : level) cin >> i;
		
		Node* root = nullptr;
		root = BT(root, 0, level, n);
		PostOrder(root);
		cout << endl;
		
		root = nullptr;
		delete root;
	}

	return 0;
}


