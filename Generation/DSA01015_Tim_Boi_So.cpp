#include<bits/stdc++.h>
using namespace std;

bool trace[501] = {false};
long long value[501] = {0};
bool isLast;
string init(10,'0');

void genBin() {
	int i = init.size()-1;
	while(i >= 0 && init[i] == '9') {
		init[i] = '0';
		i--;
	}
	if(i < 0) {
		isLast = true;
	} else {
		init[i] = '9';
	}
}

void check() {
	long long tmp = stoll(init);
	for(int i = 1; i <= 500; i++) {
		if(tmp % i == 0 && trace[i] == false) {
			value[i] = tmp;
			trace[i] = true;
		}
	}
}

void sieve() {
	genBin();
	while(!isLast) {
		check();
		genBin();
	}
}

int main() {
	sieve();
	int t;
	cin >> t;
	while(t--) {
		int n = 0;
		cin >> n;
		cout << value[n] << endl;
	}
}
