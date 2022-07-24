#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Point {
	int x, y;
};

bool cmpX(Point a, Point b) {
	return (a.x < b.x);
}
double dist(Point a, Point b) {
	return hypot(a.x - b.x, a.y - b.y);
}
double Brute_Force(Point x[], int n) {
	double res = DBL_MAX;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
			res = min(res, dist(x[i], x[j]));
	}
	return res;
}

double closestTemp(Point temp[], int len, double d) {
	double res = d;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len && (temp[j].y - temp[i].y) < res; j++)
			res = min(res, dist(temp[i], temp[j]));
	}
	return res;
}

double closest(Point Px[], int n) {
	if (n <= 3)
		return Brute_Force(Px, n);
	int mid = n / 2;
	Point midPoint = Px[mid];
	double dl = closest(Px, mid);
	double dr = closest(Px + mid, n - mid);
	double d = min(dl, dr);
	Point temp[n];
	int len = 0;
	for (int i = 0; i < n; i++) {
		if (abs(Px[i].x - midPoint.x) < d)
			temp[len++] = Px[i];
	}
	return closestTemp(temp, len, d);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Point a[n], Px[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i].x >> a[i].y;
			Px[i] = a[i];
		}
		sort(Px, Px + n, cmpX);
		cout << fixed << setprecision(6) << closest(Px, n) << "\n";
	}
	return 0;
}
