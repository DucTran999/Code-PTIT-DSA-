#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

vector<int> ans;

struct Node {
	int data;
	Node* left, *right;
	Node(int x) {
		data =  x;
		left = right = nullptr;
	}
};

void insert(Node* &root, int val) {
	if(!root) {
		root = new Node(val);
		return;
	}
	if(root->data > val) insert(root->left, val);
	if(root->data < val) insert(root->right, val);
}

void inorder(Node* root) {
	if(!root) return;
	inorder(root->left);
	ans.push_back(root->data);
	inorder(root->right);
}

bool isSame(int *A, int n) {
	for(int i = 0; i < n; i++)
		if(A[i] != ans[i])
			return false;
	return true;
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		Node* root = nullptr;
		for(int i = 0; i < n; i++) {
			cin >> A[i];
			insert(root, A[i]);
		}
		inorder(root);
		cout << isSame(A, n) << endl;
		ans.clear();
	}

	return 0;
}


