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

Node* createBST(int *A, int start, int end) {
	if(start > end) return nullptr;
	int mid = (start + end) / 2;
	Node* root = new Node(A[mid]);
	root->left = createBST(A, start, mid-1);
	root->right = createBST(A, mid+1, end);
	return root;
}

void dfs(Node* root) {
	if(!root)return;
	cout << root->data << " ";
	dfs(root->left);
	dfs(root->right);
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int i = 0; i < n; i++) {
			cin >> A[i];
		}
		sort(A, A+n);
		Node* root = createBST(A, 0, n-1);
		dfs(root);
		cout << endl;
		root = nullptr;
		delete root;
	}

	return 0;
}


