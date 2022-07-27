#include<bits/stdc++.h>
using namespace std;

int mc[20][20];
int n, ok;
set<string> solution;

void inp() {
	cin >> n;
	for(int i = 0; i< n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> mc [i][j];
		}
	}
	ok = 0;
	solution.clear();
}

void findWay(int X, int Y,string path) {

	if (mc[0][0] == 0 || mc[n-1][n-1] == 0)
		return;

	if(X == n-1 && Y == n-1) {
		solution.insert(path);
		ok = 1;
		return;
	}
	if(mc[X+1][Y] == 1 && X < n) {
		findWay(X+1,Y, path+="D");
		path.pop_back();
	}
	if(mc[X][Y+1] == 1 && Y < n) {
		findWay(X,Y+1, path+="R");
		path.pop_back();
	}
}

int main() {
	int t;

	cin >> t;
	while(t--) {
		inp();
		string path = "";
		findWay(0,0, path);
		if(!ok) cout << -1;
		else {
			for(string s : solution) {
				cout << s << " ";
			}
		}
		cout <<endl;
	}

	return 0;
}

