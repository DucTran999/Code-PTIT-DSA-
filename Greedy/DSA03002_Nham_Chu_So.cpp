#include<bits/stdc++.h>
using namespace std;
#define ll long long

void findMin(string a, string b) {
	int min = 0;
	for(int i = 0; i < a.size(); i++) {
		if(a[i] == '6') {
			a[i] = '5';
		}
	}
	for(int i = 0; i < b.size(); i++) {
		if(b[i] == '6') {
			b[i] = '5';
		}
	}
	min = stoi(a) + stoi(b);
	cout << min << " ";
}

void findMax(string a, string b) {
	int max = 0;
	for(int i = 0; i < a.size(); i++) {
		if(a[i] == '5') {
			a[i] = '6';
		}
	}
	for(int i = 0; i < b.size(); i++) {
		if(b[i] == '5') {
			b[i] = '6';
		}
	}
	max = stoi(a) + stoi(b);
	cout << max << endl;
}

int main() {
	string a, b;
	cin >> a >> b;
	findMin(a, b);
	findMax(a, b);
	return 0;
}

