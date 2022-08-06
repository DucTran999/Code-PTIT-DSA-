#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int n,  A[100];

// 1 : 8  0 : 6
void check(){
	if(A[1] != 1 or A[n] != 0) return;
	for(int i = 1; i < n; i++){
		if(A[i] == 1 and A[i+1] == 1) return;
	}
	for(int i = 1; i < n-2; i++){
		if(A[i] == 0 and A[i+1] == 0 and A[i+2] == 0 and A[i+3] == 0)return;
	}
	for(int i = 1; i <= n; i++){
		if(A[i] == 1) cout << 8;
		else cout << 6;
	}
	cout << endl;
}

void Try(int i){
	int j;
	for(int j = 0;j<=1;j++){
		A[i] = j;
		if(i == n){
			check();
		}else Try(i+1);
	}
}

int main(){
	sync();
	rs(A);
	n = 0;
	cin >> n;
	Try(1);
	
	return 0;
}


