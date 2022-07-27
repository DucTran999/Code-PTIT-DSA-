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

Node* createBST(int a[], int start, int end) {
	if(start > end) return nullptr;
	int mid = (start + end)/2;
	Node* root = new Node(a[mid]);
	root->left = createBST(a, start, mid - 1);
	root->right = createBST(a, mid + 1, end);
	return root;
}

void printPostorder(Node* root) {
	if(!root) return;
	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->data << " ";
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int a[n];
		for(int i = 0; i <  n; i++) cin >> a[i];
		sort(a, a+n);
		Node *root = createBST(a, 0, n - 1);
		printPostorder(root);
		cout << endl;
	}

	return 0;
}


