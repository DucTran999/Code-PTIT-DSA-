#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);

int n, m;
vi List[1005];
int degreeIn[1005];
int degreeOut[1005];

void inp() {
	memset(List, 0, sizeof(List));
	memset(degreeIn, 0, sizeof(degreeIn));
	memset(degreeOut, 0, sizeof(degreeOut));
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		List[x].push_back(y);
		degreeIn[y]++;
		degreeOut[x]++;
	}
}

bool checkEulerCycle() {
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(degreeIn[i] != degreeOut[i])
			return false;
	}
	return true;
}

int main() {
	sync();
	int t = 1;
	cin >> t;
	while(t--) {
		inp();
		bool EC = checkEulerCycle();
		if(EC) cout << 1;
		else cout << 0;
		cout << endl;
	}

	return 0;
}


