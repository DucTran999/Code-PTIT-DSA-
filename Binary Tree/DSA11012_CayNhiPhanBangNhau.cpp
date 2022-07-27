#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

struct Node {
	int data;
	Node* right, *left;
	Node(int x) {
		data = x;
		right = left = nullptr;
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

bool isEqual(Node* A, Node* B) {
	if(!A and !B) return true;
	if(A and B) {
		return ((A->data == B->data) and
		        isEqual(A->left, B->left) and
		        isEqual(A->right, B->right));
	}
	return false;
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		Node* A = BuildTree();
		Node* B = BuildTree();
		cout << isEqual(A, B) << endl;
		A = B = nullptr;
		delete A;
		delete B;
	}

	return 0;
}


