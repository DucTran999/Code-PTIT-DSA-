#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

struct Node {
	int data;
	Node *left, *right;
	Node(int x) {
		data =  x;
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

int depth(Node* root) {
	if(root == nullptr) return 0;
	return max(depth(root->left), depth(root->right)) + 1;
}

bool isPerfectTree(Node* root, int curNode) {
	int d = depth(root);
	int maxNode = pow(2, d) - 1;
	return maxNode == curNode;
}

int main() {
	sync();
	int t = 1, n, p, c;
	char pos;
	cin >> t;
	while(t--) {
		cin >> n;
		int curNode = n + 1;
		Node* root = nullptr;
		while(n--) {
			cin >> p >> c >> pos;
			if(!root) {
				root = new Node(p);
				if(pos == 'L') root->left = new Node(c);
				else root-> right = new Node(c);
			} else insert(root, p , c , pos);
		}
		if(isPerfectTree(root, curNode)) cout << "Yes";
		else cout << "No";
		cout << endl;
		root = nullptr;
		delete root;
	}
	return 0;
}
