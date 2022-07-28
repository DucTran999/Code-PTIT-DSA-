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
		left = right =  nullptr;
	}
};

Node *createBST(int *A,int start,int end) {
	if(start > end) return nullptr;
	int mid =(start + end) / 2;
	Node *tmp = new Node(A[mid]);
	tmp->left = createBST(A, start, mid - 1);
	tmp->right = createBST(A, mid + 1, end);
	return tmp;
}

int dfs(Node* root, int& cnt) {
	if(root == nullptr) return 0;
	if(root->left == nullptr and root->right == nullptr) return cnt++;
	dfs(root->left, cnt);
	dfs(root->right, cnt);
	return cnt;
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int i = 0; i < n; i++) cin >> A[i];
		sort(A, A + n);
		Node *root = createBST(A, 0, n - 1);
		int cnt = 0;
		cout << dfs(root, cnt) << endl;
		root = nullptr;
		delete root;
	}
	return 0;
}
