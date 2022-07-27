#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);


inline int max(int a, int b) {
	return (a > b) ? a : b;
}

struct Node {
	int data;
	Node* left, *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};

void insert(Node* root, int p, int c, char pos) {
	if(root == nullptr) return;
	if(root->data == p) {
		if(pos == 'L') root->left = new Node(c);
		else root->right = new Node(c);
		return;
	} else {
		insert(root->left, p, c, pos);
		insert(root->right, p, c, pos);
	}
}

int findTreeDepth(Node* root) {
	if(root == nullptr) return 0;
	else {
		return max(findTreeDepth(root->left)+1, findTreeDepth(root->right)+1);
	}
}

int main() {
	sync();
	int t = 1, n, p, c;
	char pos;
	cin >> t;
	while(t--) {
		cin >> n;
		int curNode = n+1;
		Node* root = nullptr;
		while(n--) {
			cin >> p >> c >> pos;
			if(root == nullptr) {
				root = new Node(p);
				if(pos == 'L') root->left = new Node(c);
				else root->right = new Node(c);
			} else insert(root, p , c, pos);
		}
		int h = findTreeDepth(root);
		int maxNode = pow(2, h) - 1;
		if(curNode == maxNode) cout << 1 << endl;
		else cout << 0 << endl;
		root = nullptr;
		delete root;
	}

	return 0;
}


