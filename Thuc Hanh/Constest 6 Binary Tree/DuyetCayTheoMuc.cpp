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

void insert(Node* root, int p, int c, char pos) {
	if(!root) return;
	if(root->data == p) {
		if(pos == 'L') root->left = new Node(c);
		else root->right = new Node(c);
	} else {
		insert(root->left, p, c, pos);
		insert(root->right, p, c, pos);
	}
}

void bfs(Node* root) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* tmp = q.front();
		cout << tmp->data<< ' ';
		q.pop();
		if(tmp->left) q.push(tmp->left);
		if(tmp->right) q.push(tmp->right);
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
				else root-> right = new Node(c);
			} else insert(root, p , c , pos);
		}
		bfs(root);
		cout << endl;
		root = nullptr;
		delete root;
	}
	return 0;
}
