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
		right = left = nullptr;
	}
};

void insert(Node* r, int p, int c, int pos) {
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
	Node *tree = nullptr, *parent, *child;
	map<int, Node*> m;
	while(n--) {
		cin >> p >> c >> pos;
		if(m.find(p) == m.end()) {
			parent = new Node(p);
			m[p] = parent;
			if(!tree) tree = parent;
		} else parent = m[p];

		child = new Node(c);
		if(pos == 'L') parent->left = child;
		else  parent->right = child;
		m[c] = child;
	}
	return tree;
}

ll rightLeafSum(Node* A) {
	if (!A)	return 0;
	ll sum = 0;
	queue<Node*> q;
	q.push(A);
	while(!q.empty()) {
		Node *tmp = q.front();
		q.pop();
		if (tmp->left) q.push(tmp->left);
		if (tmp->right) {
			if (!tmp->right->right and !tmp->right->left) {
				sum += tmp->right->data;
			}
			q.push(tmp->right);
		}
	}
	return sum;
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		Node* A = BuildTree();
		cout << rightLeafSum(A) << endl;
		A = nullptr;
		delete A;
	}

	return 0;
}


