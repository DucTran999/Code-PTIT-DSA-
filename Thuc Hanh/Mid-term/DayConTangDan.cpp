/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

int n, A[100], B[100];
bool isLast;
vector<string> ans;

void init(int k) {
	for(int i = 1; i <= k; i++) B[i] = i;
}

void nextCom(int k) {
	int i = k;
	while(i > 0 and B[i] == n - k + i) i--;
	if(i==0)isLast=true;
	B[i]++;
	for(int j = i + 1; j<=k; j++) {
		B[j] = B[j-1] + 1;
	}
}

void check(int k){
	string tmp;
	for(int i = 1; i< k; i++){
		tmp += (to_string(A[B[i]])+" ");
		if(A[B[i]] > A[B[i+1]]) return;
	}
	tmp += (to_string(A[B[k]])+" ");
	ans.push_back(tmp);
}
void in()
{
	sort(ans.begin(), ans.end());
	for(string s : ans){
		cout << s << endl;
	}
}
int main() {
	sync();
	cin >> n;
	rs(A);
	ans.clear();
	for(int i = 1; i<=n; i++) cin >> A[i]; //input
	for(int i = 2; i <= n; i++) {
		init(i);
		while(!isLast) {
			check(i);
			nextCom(i);
		}
		isLast = false;
	}
	in();
	return 0;
}


