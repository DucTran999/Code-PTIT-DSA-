#include<bits/stdc++.h>
using namespace std;

int n, k;
int Data[25];
int ok = 0;

vector<int> tmp;

void inp() {
	cin >>  n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> Data[i];
	}
}

void in() {
	cout << "[";
	for(int i = 0; i < tmp.size()-1; i++) {
		cout << tmp[i] <<" ";
	}
	cout << tmp[tmp.size()-1] << "]";
}

void Try(int i, int target) {
	if(i == n+1) {
		if(target == 0) {
			ok = 1;
			in();
		}
		return;
	}

	if(Data[i] <= target) {
		tmp.push_back(Data[i]);
		Try(i, target - Data[i]);
		tmp.pop_back();
	}

	Try(i+1, target);
}


int main() {

	int t;
	cin >>t;
	while(t--) {
		inp();
		Try(1,k);
		if(ok == 0) {
			cout << -1;
		}
		tmp.clear();
		cout << endl;
	}

	return 0;
}

