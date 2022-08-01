#include<bits/stdc++.h>
using namespace std;



void nextBin(string X, int n) {
	int i = n-1;
	while(i >=0 && X[i] == '1') {
		X[i] ='0';
		--i;
	}
	if(i < 0) {
		cout << X << endl;
		return;
	} else {
		X[i] = '1';
	}
	cout << X << endl;
}


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>> t;
	while(t--) {
		string s;
		cin >> s;
		nextBin(s,  s.size());
	}

	return 0;
}



