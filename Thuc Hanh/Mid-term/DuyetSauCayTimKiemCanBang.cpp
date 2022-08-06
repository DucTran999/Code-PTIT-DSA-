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

Node* createBST(int *A, int s, int e) {
	if(s > e) return nullptr;
	int mid = (s+e)/2;
	Node* root = new Node(A[mid]);
	root->left = createBST(A, s, mid-1);
	root->right = createBST(A, mid+1,e);
	return root;
}

void dfs(Node* root) {
	if(root == nullptr) return;
	dfs(root->left);
	dfs(root->right);
	cout << root->data << " ";
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int &i : A) cin >> i;
		sort(A,A+n);
		Node* root = createBST(A,0,n-1);
		dfs(root);
		cout << endl;
		root=nullptr;
		delete root;
	}

	return 0;
}


