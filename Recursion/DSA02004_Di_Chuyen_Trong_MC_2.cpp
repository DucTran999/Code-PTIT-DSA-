#include<bits/stdc++.h>
using namespace std;

int mc[10][10];
bool trace[10][10];
int n;
string path = "";
vector<string> ans;

bool f;

void inp() {
	cin >> n;
	f = false;
	memset(trace, false,sizeof(trace));
	for(int i = 0; i<n; i++)
		for(int j = 0; j < n; j++)
			cin >> mc[i][j];
}

void findWay(int X, int Y) {
	if(mc[0][0] == 0 || mc[n-1][n-1] == 0) return;

	if(X == n-1 && Y == n-1) {
		f = true;
		ans.push_back(path);
		return;
	}
	trace[X][Y] = true;
	if(mc[X+1][Y] == 1 && trace[X+1][Y] == false && X < n-1) {
		path+="D";
		findWay(X+1, Y);
		path.pop_back();

	}

	if(mc[X][Y+1] == 1 && trace[X][Y+1] == false && Y < n-1) {
		path+="R";
		findWay(X, Y+1);
		path.pop_back();

	}

	if(mc[X-1][Y] == 1 && trace[X-1][Y] == false && X >= 0) {
		path+="U";
		findWay(X-1, Y);
		path.pop_back();
	}

	if(mc[X][Y-1] == 1 && trace[X][Y-1] == false && Y >= 0) {
		path+="L";
		findWay(X, Y-1);
		path.pop_back();
	}
	trace[X][Y] = false;
}

void in() {
	sort(ans.begin(), ans.end());
	for(string s : ans) {
		cout << s << " ";
	}
	ans.clear();
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		inp();
		findWay(0,0);
		if(f == false) {
			cout << -1;
		} else {
			in();
		}
		cout << endl;
	}
	return 0;
}

