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

void insert(Node* &root, int val) {
	if(!root) {
		root = new Node(val);
		return;
	}
	if(root -> data > val) insert(root->left, val);
	if(root -> data < val) insert(root->right, val);
}

int depth(Node* root) {
	if(root == nullptr) return -1;
	return max(depth(root->left), depth(root->right))+1;
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		Node* root = nullptr;
		int A[n];
		for(int i = 0; i < n; i++) {
			cin >> A[i];
			insert(root, A[i]);
		}
		cout << depth(root) << endl;
		root = nullptr;
		delete root;
	}

	return 0;
}


