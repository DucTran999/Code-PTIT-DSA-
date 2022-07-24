#include<bits/stdc++.h>
using namespace std;

string A[10] = {"02", "20","22"};
int B[10];
bool isLast;

void init() {
	for(int i = 1; i <= 3; i++) {
		B[i] = 0;
	}
}

void genBin() {
	int i = 3;
	while ( i >= 0 && B[i] == 1) {
		B[i] = 0;
		i--;
	}
	if(i < 1) {
		isLast = true;
	} else {
		B[i] = 1;
	}
}

void in(int x) {
	cout << A[x];
	cout <<"/02/2";
	for(int i = 1; i <= 3; i++) {
		if(B[i] == 1)
			cout << 2;
		else cout << B[i];
	}
	cout << endl;
}

int main() {

	for(int i = 0; i < 3; i++) {
		while(!isLast){
			in(i);
			genBin();
		}
		isLast = false;
	}

	return 0;
}

