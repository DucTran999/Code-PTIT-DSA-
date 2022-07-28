#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

struct Node {
	int data;
	Node *left, *right;
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
	root->right = createBST(A, mid + 1, end);
	return root;
}

void postorder(Node* root) {
	if(root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << ' ';
}

int main() {
	sync();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int A[n];
		for(int &i : A) {
			cin >> i;
		}
		sort(A, A+n);
		Node* root = createBST(A, 0, n-1);
		postorder(root);
		cout << endl;
		root = nullptr;
		delete root;
	}

	return 0;
}
