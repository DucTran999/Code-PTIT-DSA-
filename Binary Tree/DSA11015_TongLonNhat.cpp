#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

ll max(ll a, ll b) {
	return (a > b) ? a : b;
}
struct Node {
	int data;
	Node* left, *right;
	Node(int x) {
		data = x;
		right = left = nullptr;
	}
};

ll findMaxSumPath(Node* root, ll &max_sum) {
	if (root == nullptr) {
		return 0;
	}
	ll left = findMaxSumPath(root->left, max_sum);
	ll right = findMaxSumPath(root->right, max_sum);
	if (root->left == nullptr) {
		return right + root->data;
	}
	if (root->right == nullptr) {
		return left + root->data;
	}
	ll cur_sum = left + right + root->data;
	max_sum = max(cur_sum, max_sum);
	return max(left, right) + root->data;
}

ll findMaxSum(Node *root) {
	ll res = LONG_MIN;
	findMaxSumPath(root, res);
	return res;
}

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

Node* BuildTree() {
	int n, p, c;
	char pos;
	cin >> n;
	Node* root = nullptr;
	while(n--) {
		cin >> p >> c >> pos;
		if(!root) {
			root = new Node(p);
			if(pos == 'L') root->left = new Node(c);
			else root->right = new Node(c);
		} else insert(root, p, c, pos);
	}
	return root;
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		Node* A = BuildTree();
		cout << findMaxSum(A);
		A = nullptr;
		delete A;
		cout << endl;
	}

	return 0;
}


