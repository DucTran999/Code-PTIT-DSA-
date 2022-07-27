#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

int n;
string A[1005];

struct Node {
	string data;
	Node* left, *right;
	Node(string val) {
		data = val;
		left = right = nullptr;
	}
};

Node* PBT(Node* root, int i) {
	if(i < n) {
		root = new Node(A[i]);
		root->left = PBT(root->left , (i<<1) + 1);
		root->right = PBT(root->right, (i<<1) + 2);
	}
	return root;
}

ll calc(ll a, ll b, string op) {
	if(op == "+") return a + b;
	if(op == "-") return a - b;
	if(op == "*") return a * b;
	if(op == "/") return a / b;
}

ll postOrder(Node* root) {
	if(root == nullptr) return 0;
	if (!root->left and !root->right)
		return stoll(root->data);
	return calc(postOrder(root->left), postOrder(root->right), root->data);
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) cin >> A[i];
		Node* root = nullptr;
		root = PBT(root, 0);
		cout << postOrder(root) << endl;
		root = nullptr;
		delete root;
	}
	return 0;
}


