#include<bits/stdc++.h>
using namespace std;

string a, b;
int k;

void cal() {
	while(a.size() < b.size()) {
		a = "0" + a;
	}
	while(b.size()< a.size()) b = "0" + b;
	int carry =0;
	string ans ="";

	for(int i = a.size()-1; i>=0; i--) {
		int	sum = int(a[i] - '0') + int(b[i] -'0') + carry;
		carry = sum/k;
		ans = char(sum%k + '0') + ans;
	}

	if(carry > 0) {
		ans = char(carry + '0') + ans;
	}
	cout << ans << endl;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		cin >> k >> a >> b;
		cal();
	}
	return 0;
}

