#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

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

void bfs(Node* root) {
	deque<Node*> dq;
	stack<Node*> st;
	dq.push_front(root);
	while(!dq.empty()) {
		root = dq.front();
		dq.pop_front();
		st.push(root);
		if(root->left) dq.push_front(root->left);
		if(root->right) dq.push_front(root->right);
	}
	while(!st.empty()) {
		cout << st.top()->data << " ";
		st.pop();
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
		bfs(root);
		cout << endl;
	}
	return 0;
}
