#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long sum =  0;
	while(n--) {
		int tmp;
		cin >> tmp;
		sum += (tmp+abs(tmp));
	}
	cout << sum << endl;
	return 0;
}

