#include<bits/stdc++.h>
using namespace std;

int A[100];
int Data[100];
vector<vector<int>> v;
vector<int> tmp;

int n;
bool isPrime[1600];

void inp() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> Data[i];
	}
	sort(Data+1, Data+n+1, greater<int>());
	v.clear();
}

void sieve() {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2; i <= sqrt(1500); ++i) {
		if(isPrime[i] == 1) {
			for(int j = i*i; j <= 1500; j+=i) {
				isPrime[j] = 0;
			}
		}
	}
}

void in() {
	sort(v.begin(), v.end());
	for(auto tmp : v) {
		for(auto i : tmp) {
			cout << i << " ";
		}
		cout << endl;
	}
}

void Try(int i, int sum) {
	if(isPrime[sum]) v.push_back(tmp);
	if(i > n) return;
	for(int j = i; j <= n; ++j) {
		tmp.push_back(Data[j]);
		Try(j + 1, sum + Data[j]);
		tmp.pop_back();
	}
}

int main() {
	sieve();
	int t = 1;
	cin >> t;
	while(t--) {
		inp();
		Try(1,0);
		in();
	}

	return 0;
}


