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

Node* createBST(int *A, int s, int e) {
	if(s > e) return nullptr;
	int mid = (s + e) / 2;
	Node* root = new Node(A[mid]);
	root->left = createBST(A, s, mid - 1);
	root->right = createBST(A, mid + 1, e);
	return root;
}

int bfs(Node* root) {
	int cnt = 0;
	queue<Node*>q;
	q.push(root);
	while(!q.empty()) {
		Node* tmp = q.front();
		if(!tmp->left and !tmp->right) cnt++;
		q.pop();
		if(tmp->left) q.push(tmp->left);
		if(tmp->right) q.push(tmp->right);
	}
	return cnt;
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		int A[n];
		for(int &i : A) cin >> i;
		sort(A, A+n);
		Node* root = createBST(A, 0, n-1);
		cout << bfs(root) << endl;
		root = nullptr;
		delete root;
	}

	return 0;
}


