#include<bits/stdc++.h>
using namespace std;
#define ll long long

void findUnitFraction(ll num, ll de) {
	ll x = 0;
	while(1) {
		if(de % num == 0) {
			cout << "1/" << de / num << endl;
			return;
		}
		x = de / num + 1;
		cout << "1/" << x << " + ";
		num = x * num - de;
		de *= x;
	}
}

int main() {
	int t = 1;
	cin >> t;
	ll num, de;
	while(t--) {
		cin >> num >> de;
		findUnitFraction(num, de);
	}

	return 0;
}
