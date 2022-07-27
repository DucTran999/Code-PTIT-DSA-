#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0);

void selectionSort(int *A,  int n) {
	for(int i = 0; i < n - 1; i++) {
		int min_i = i;
		for(int j = i + 1; j < n; j++) {
			if(A[j] < A[min_i])
				min_i = j;
		}
		swap(A[i], A[min_i]);
		cout << "Buoc " <<  i + 1 << ": ";
		for(int k = 0; k < n; k++) cout << A[k] <<" ";
		cout << endl;
	}
}

int main() {
	sync();
	int n;
	cin >> n;
	int A[n];
	for(int &i : A) cin >> i;
	selectionSort(A, n);

	return 0;
}


