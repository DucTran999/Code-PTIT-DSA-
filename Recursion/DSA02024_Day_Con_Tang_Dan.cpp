#include<bits/stdc++.h>
using namespace std;

int Data[100];
int A[100];
int n;
vector<string> v;
bool isLast;

void inp() {
	cin >> n;
	for(int i = 1; i<=n; i++) {
		cin >> Data[i];
	}
}

void init(int k) {
	for(int i = 1; i <= k; i++) {
		A[i] = i;
	}
}

void genCom(int k) {
	int i = k;
	while(i > 0 && A[i] == n- k + i) {
		i--;
	}
	if(i == 0)
		isLast = true;
	else {
		A[i]++;
		for(int j = i+1; j<=k; j++)
			A[j] = A[j-1] + 1;
	}
}

bool check(int k) {
	for(int i = 1; i < k; i++) {
		if(Data[A[i]] > Data[A[i+1]]) {
			return false;
		}
	}
	return true;
}

void add(int i) {
	string tmp ="";
	for(int j = 1; j <= i; j++)
		tmp+= to_string(Data[A[j]] )+ " ";
	v.push_back(tmp);
}

void in() {
	sort(v.begin(), v.end());
	for(string tmp : v) {
		cout << tmp << endl;
	}
}

int main() {
	inp();
	for(int i = 2; i < n; i++) {
		init(i);
		while(!isLast) {
			if(check(i)) {
				add(i);
			}
			genCom(i);
		}
		isLast = false;
	}
	in();
	v.clear();
	return 0;
}

