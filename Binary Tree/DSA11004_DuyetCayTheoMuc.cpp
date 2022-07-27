#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

struct Node {
	int data;
	Node* left, *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};

void insert(Node* r, int p, int c, int pos) {
	if(r == nullptr) return;
	if(r->data == p) {
		if(pos == 'L') r->left = new Node(c);
		else r->right = new Node(c);
		return;
	} else {
		insert(r->left, p, c, pos);
		insert(r->right, p, c, pos);
	}
}

void LevelOrderTraversal(Node *root) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node *tmp = q.front();
		cout << tmp->data <<" ";
		q.pop();
		if(tmp->left != nullptr) q.push(tmp->left);
		if(tmp->right != nullptr) q.push(tmp->right);
	}
}

int main() {
	sync();
	int t = 1, n;
	cin >> t;
	while(t--) {
		cin >> n;
		Node *root = nullptr;
		while(n--) {
			int p, c;
			char pos;
			cin >> p >> c >> pos;
			if(root == nullptr) {
				root = new Node(p);
				if(pos == 'L') root->left = new Node(c);
				else root->right = new Node(c);
			} else insert(root, p, c ,pos);
		}
		LevelOrderTraversal(root);
		cout << endl;
	}

	return 0;
}


