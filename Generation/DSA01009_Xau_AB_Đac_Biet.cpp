#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>

using namespace std;

int a[100];
int n, k;
bool isLast;

void init() {
	for(int i = 1; i <= n; i++) {
		a[i] = 0;
	}
}

void print(vector<int> a) {
	for(int it : a) {
		if(it == 1) cout << 'B';
		else cout << 'A';
	}
	cout << endl;
}

void gen() {
	int i = n;
	while(i > 0 && a[i] == 1) {
		a[i] = 0;
		i--;
	}
	if(i == 0) isLast =true;
	else a[i] = 1;
}

bool check() {
	int cnt = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == 0)
			++cnt;
		else
			cnt = 0;
		if(cnt > k)
			return false;
		if(cnt == k) ++ans;
	}
	return ans == 1;
}

int main() {

	cin >> n >> k;
	vector<vector<int>> v;
	init();
	while(!isLast) {
		if(check() == 1) {
			vector<int> tmp(a + 1, a+n+1);
			v.push_back(tmp);
		}
		gen();
	}
	cout << v.size() << endl;
	for(vector<int> tmp : v) {
		print(tmp);
	}

	return 0;
}

