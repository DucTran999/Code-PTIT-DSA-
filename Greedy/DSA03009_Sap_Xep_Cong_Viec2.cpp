#include<bits/stdc++.h>
using namespace std;

struct Job {
	int id;
	int deadline;
	int profit;
};

bool comp(Job a, Job b) {
	return a.profit > b.profit;
}

void inp(Job scheduled[], int n) {
	int id, deadline, profit;
	for(int i = 0; i<n; i++) {
		cin >> scheduled[i].id >> scheduled[i].deadline>> scheduled[i].profit;
	}
	sort(scheduled, scheduled+n, comp);
}

void solve(Job scheduled[], int n) {
	int cnt = 0, pro = 0;
	bool slot[n];
	memset(slot, false, sizeof(slot));
	for(int i = 0; i < n; i++) {
		for(int j = min(n, scheduled[i].deadline)-1; j >=0; j--) {
			if(slot[j] == false) {
				slot[j] = true;
				pro += scheduled[i].profit;
				cnt++;
				break;
			}
		}
	}
	cout << cnt << " " << pro << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		Job scheduled[n];
		inp(scheduled, n);
		solve(scheduled,n);
	}
	return 0;
}

