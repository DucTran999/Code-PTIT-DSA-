#include<bits/stdc++.h>
using namespace std;

int n;
int c[100], d1[100], d2[100];
int X[100];
int cnt;

void inp() {
	cin >> n;
	memset(c, 0, sizeof(0));
	memset(d1, 0, sizeof(0));
	memset(d2, 0, sizeof(0));
	memset(X, 0, sizeof(0));
	cnt = 0;
}
ad
void Try(int i) {
	for(int j = 1; j <= n; j++) {
		if(c[j] == 0 && d1[i+j-1] == 0 && d2[i-j+n] == 0) {
			X[i] = j;
			c[j] = d1[i+j-1] = d2[i-j+n] = 1;
			if(i == n) {
				cnt++;
			} else Try(i+1);
			c[j] = d1[i+j-1] = d2[i-j+n] = 0;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		Try(1);
		cout << cnt << endl;
	}

	return 0;
}

