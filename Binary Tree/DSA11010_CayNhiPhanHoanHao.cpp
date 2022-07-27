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

int depth(Node* r) {
	if(!r) return 0;
	else {
		return max(depth(r->left) + 1, depth(r->right) + 1);
	}
}

void checkPerfectTree(Node* root, int curNode) {
	int h = depth(root);
	if(curNode == pow(2,h)-1) cout <<"Yes\n";
	else cout << "No\n";
}

int main() {
	sync();
	int t = 1, n, p, c;
	char pos;
	cin >> t;
	while(t--) {
		cin >> n;
		int curNode = n+1;
		Node* root  = nullptr;
		while(n--) {
			cin >> p >> c >> pos;
			if(!root) {
				root = new Node(p);
				if(pos == 'L') root->left = new Node(c);
				else root->right = new Node(c);
			} else insert(root, p, c, pos);
		}
		checkPerfectTree(root, curNode);
		root = nullptr;
		delete root;
	}

	return 0;
}


