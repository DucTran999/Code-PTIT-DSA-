#include<bits/stdc++.h>
using namespace std;

string toBin(string& gray, int size) {
	string bin = "";
	bin.push_back(gray[0]);

	for(int i = 1; i < size ; i++) {
		if(gray[i] != bin[i-1]) {
			bin+='1';
		} else
			bin+='0';
	}

	return bin;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string gray;
		cin >> gray;
		cout << toBin(gray, gray.size()) << endl;
	}

	return 0;
}

