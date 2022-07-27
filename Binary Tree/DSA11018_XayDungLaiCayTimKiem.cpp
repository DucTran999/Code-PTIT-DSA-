#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

struct Node {
	int data;
	Node* left, * right;
	Node(int x) {
		data = x;
		left = right = nullptr;
	}
};

void insert(Node* &root,int val) {
	if(root ==  nullptr) {
		root = new Node(val);
		return;
	}
	if(root->data > val) insert(root->left,val);
	if(root->data < val) insert(root->right,val);
}

void preorder(Node* root) {
	if(!root) return;
	cout << root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n+5];
		Node* root = nullptr;
		for(int i = 1; i <= n; i++) {
			cin >> A[i];
			insert(root,A[i]);
		}
		preorder(root);
		cout << endl;
	}

	return 0;
}


