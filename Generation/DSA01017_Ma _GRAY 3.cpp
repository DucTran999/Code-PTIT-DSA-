#include<bits/stdc++.h>
using namespace std;

void toGray(string& bin, int size) {
	string gray = "";
	gray.push_back(bin[0]);
	for(int i = 1; i < size; i++) {
		if(bin[i] != bin[i-1]) {
			gray+='1';
		} else {
			gray+='0';
		}
	}

	cout << gray << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		string bin;
		cin >> bin;
		toGray(bin, bin.size());
	}
	return 0;
}

