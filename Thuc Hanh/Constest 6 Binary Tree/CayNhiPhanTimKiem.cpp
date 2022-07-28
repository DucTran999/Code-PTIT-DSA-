#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

struct Node {
	int data;
	Node *left, *right;
	Node(int x) {
		data =  x;
		left = right = nullptr;
	}
};

void insert(Node* &root, int val) {
	if(root==nullptr) {
		root= new Node(val);
		return;
	}
	if(root->data > val) insert(root->left, val);
	if(root->data < val) insert(root->right, val);
}

Node* leftLeaf(Node* node) {
	Node* tmp = node;
	while(tmp and tmp->left != nullptr) {
		tmp = tmp->left;
	}
	return tmp;
}

Node* remove(Node* root, int val) {
	if(root == nullptr) return root;
	if(val < root->data)
		root->left = remove(root->left, val);
	else if (val > root->data)
		root->right = remove(root->right, val);
	else {
		if(root->left == nullptr and root->right == nullptr)
			return nullptr;
		else if (root->left == nullptr) {
			Node* tmp = root->right;
			delete root;
			return tmp;
		} else if (root->right == nullptr) {
			Node* tmp = root->left;
			delete root;
			return tmp;
		}
		Node* tmp = leftLeaf(root->right);
		root->data = tmp->data;
		root->right = remove(root->right, tmp->data);
	}
	return root;
}

void preorder(Node* root) {
	if(!root) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node* root) {
	if(!root) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(Node* root) {
	if(!root) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}


int main() {
	int q = 1;
	Node* root = nullptr;
	while(true) {
		cin >> q;
		switch(q) {
			case 1:
				int val;
				cin >> val;
				insert(root, val);
				break;
			case 2:
				int tmp;
				cin >> tmp;
				root = remove(root, tmp);
				break;
			case 3:
				preorder(root);
				cout << endl;
				break;
			case 4:
				inorder(root);
				cout << endl;
				break;
			case 5:
				postorder(root);
				cout << endl;
				break;
		}
	}
	return 0;
}
