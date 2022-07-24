#include<bits/stdc++.h>
using namespace std;

void move(int n,char nguon, char trung_gian, char dich) {
	if(n == 1) cout << nguon << " -> " << dich << endl;
	else {
		move(n-1,nguon,dich,trung_gian);
		move(1,nguon, trung_gian, dich);
		move(n-1, trung_gian, nguon, dich);
	}
}

int main() {
	int n;
	cin >> n;
	move(n, 'A','B','C');
	return 0;
}

