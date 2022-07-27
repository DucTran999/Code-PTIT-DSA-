#include<bits/stdc++.h>
using namespace std;
int A[100];
int n;
bool isLast;
vector<string> ans;
string s;
void inp() {
	cin >> n >> s;
}

void init(int k) {
	for(int i = 1; i <= k; i++) {
		A[i] = i;
	}
}

void genCom(int k) {
	int i = k;
	while ( i > 0 && A[i] == n-k+i) {
		i--;
	}
	if(i == 0) {
		isLast = true;
	} else {
		A[i] ++;
		for(int j = i + 1; j <= k; j++) {
			A[j] = A[j-1] + 1;
		}
	}
}

void add(int k) {
	string tmp = "";
	for(int i = 1; i <= k; i++) {
		tmp+=s[A[i]-1];
	}
	ans.push_back(tmp);
}

void in() {
	sort(ans.begin(), ans.end());
	for(auto tmp : ans) {
		cout << tmp << " ";
	}
	cout << endl;
}

int main() {

	int t;
	cin >> t;

	while(t--) {
		inp();
		for(int i = 1; i <= n; i++) {
			init(i);
			while(!isLast) {
				add(i);
				genCom(i);
			}
			isLast = false;
		}
		in();
		ans.clear();
	}

	return 0;
}

