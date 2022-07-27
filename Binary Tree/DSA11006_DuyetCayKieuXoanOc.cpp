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

void insert(Node* r , int p, int c, char pos) {
	if(!r) return;
	if(r->data == p) {
		if(pos == 'L') r->left = new Node(c);
		else r->right = new Node(c);
	} else {
		insert(r->left, p, c, pos);
		insert(r->right, p, c, pos);
	}
}

void spiralBFS(Node* root) {
	stack<Node*> st1, st2;
	st1.push(root);
	while(st1.size() or st2.size()) {
		while(st1.size()) {
			Node* tmp = st1.top();
			cout << tmp->data << " ";
			if(tmp->right) st2.push(tmp->right);
			if(tmp->left) st2.push(tmp->left);
			st1.pop();
		}
		while(st2.size()) {
			Node* tmp = st2.top();
			cout << tmp->data << " ";
			if(tmp->left) st1.push(tmp->left);
			if(tmp->right) st1.push(tmp->right);
			st2.pop();
		}
	}
}

int main() {
	sync();
	int t = 1, n, p, c;
	char pos;
	cin >> t;
	while(t--) {
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
		spiralBFS(root);
		cout << endl;
		root = nullptr;
		delete root;
	}

	return 0;
}


