/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

struct Node {
	int data;
	Node* left, *right;
	Node(int x) {
		data = x;
		left = right = nullptr;
	}
};

Node* createBST(int *A, int n, int i) {
	if(i > n-1) return nullptr;
	Node* root = new Node(A[i]);
	root->left = createBST(A, n, 2*i+1);
	root->right = createBST(A, n, 2*i+2);
	return root;
}

void inorder(Node* root) {
	if(root == nullptr) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int &i : A) cin >> i;
		Node* root = createBST(A,n,0);
		inorder(root);
		cout << endl;
		root=nullptr;
		delete root;
	}

	return 0;
}


