#include<bits/stdc++.h>
using namespace std;

int n;
int Data[105];
vector<int> v;
int half;
int  ok;

void inp() {
	cin >> n;
	for(int i = 1; i<=n; i++) {
		cin >> Data[i];
	}
	sort(Data+1, Data+1+n);
	half = 0;
	ok = 0;
	v.clear();
}

bool preprocess() {
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		sum += Data[i];
	}
	if(sum&1) {
		return false;
	} else {
		half = sum>>1;
		for(int i = 1; i <= n; i++) {
			if(Data[i] < half)
				v.push_back(Data[i]);
			else {
				break;
			}
		}
	}
	return true;
}

void Try(int i, int sum = 0) {
	if (ok) return;
	if(sum == half) {
		ok = 1;
		cout << "YES";
		return;
	}
	if(sum > half) return;
	for(int j = i; j < v.size(); j++) {
		Try(j+1, sum + v[j]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		inp();
		if(!preprocess()) {
			cout << "NO";
		} else {
			Try(0);
			if(!ok) cout << "NO";
		}
		cout << endl;
	}
	return 0;
}

