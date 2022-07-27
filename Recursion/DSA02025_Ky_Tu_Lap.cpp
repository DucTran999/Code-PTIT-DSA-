#include <bits/stdc++.h>
using namespace std;

string Data[100];
int duplicate = INT_MAX;
bool B[100] = {false};
int A[100] = {0};
int n;

inline int min(int a, int b) {
	return (a < b) ? a : b;
}

int sameChar(string a, string b) {
	int ans = 0;
	for (auto x : a)
		for (auto y : b)
			if (x == y) {
				ans++;
				break;
			}
	return ans;
}

void Try(int i, int sum) {
	for(int j = 1; j <= n; j++) {
		if(B[j] == false) {
			A[i] = j;
			B[j] = true;
			if(i == n) {
				duplicate = min(duplicate , sum + sameChar(Data[j], Data[A[i-1]]));
			} else if(duplicate > sum && i < n) {
				Try(i + 1, sum + sameChar(Data[A[i]], Data[A[i-1]]));
			}
			B[j] = false;
		}
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> Data[i];
	}
	Try(1, 0);
	cout << duplicate << endl;

	return 0;
}

