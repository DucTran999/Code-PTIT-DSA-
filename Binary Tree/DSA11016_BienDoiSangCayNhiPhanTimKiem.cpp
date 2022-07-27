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

void insert(Node* r, int p, int c, char pos) {
	if(!r) return;
	if(r->data == p) {
		if(pos == 'L') r->left = new Node(c);
		else r->right = new Node(c);
	} else {
		insert(r->left, p, c, pos);
		insert(r->right, p, c, pos);
	}
}

Node* BuildTree(int n) {
	int p, c;
	char pos;
	Node* root = nullptr;
	while(n--) {
		cin >> p >> c >> pos;
		if(!root) {
			root = new Node(p);
			if(pos=='L') root->left = new Node(c);
			else root->right = new Node(c);
		} else insert(root, p, c, pos);
	}
	return root;
}

void InOrder(Node* root, int *A, int* idx) {
	if (!root) return;
	InOrder(root->left, A, idx);
	A[*idx] = root->data;
	(*idx)++;
	InOrder(root->right, A, idx);
}

int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int countNodes(Node* root) {
	if (!root)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}
void arrayToBST(int* A, Node* root, int* idx) {
	if (root == NULL) return;
	arrayToBST(A, root->left, idx);
	root->data = A[*idx];
	(*idx)++;
	arrayToBST(A, root->right, idx);
}

void binaryTreeToBST(Node* root) {
	if (!root) return;
	int n = countNodes(root);
	int* A = new int[n];
	int i = 0;
	InOrder(root, A, &i);
	qsort(A, n, sizeof(A[0]), compare);
	i = 0;
	arrayToBST(A, root, &i);
	delete[] A;
}

void printInorder(Node* node) {
	if (!node) return;
	printInorder(node->left);
	cout << node->data<< " ";
	printInorder(node->right);
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		Node* BT = BuildTree(n);
		binaryTreeToBST(BT);
		printInorder(BT);
		cout << endl;
		BT = nullptr;
		delete BT;
	}

	return 0;
}


