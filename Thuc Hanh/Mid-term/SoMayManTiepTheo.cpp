/* Contributed by Anh Duc */
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
#define sync(); ios_base::sync_with_stdio(0); cin.tie(nullptr);
#define rs(a); memset(a, 0, sizeof(a));

vector<ll> lucky;

void genAll() {
	queue<ll> q;
	ll tmp = 0;
	q.push(tmp);
	while(q.front() < 1e10) {
		ll x = q.front();
		q.pop();
		lucky.push_back(x);
		q.push(x*10+4);
		q.push(x*10+7);
	}
}

int main() {
	sync();
	int t = 1, a, b;
//	cin >> t;
	genAll();
	while(t--) {
		cin >> a >> b;
		ll sum = 0;
		ll pivot = lower_bound(lucky.begin()+1, lucky.end(), a)- lucky.begin();
		for(int i = a; i<=b; i++){
			if(i <= lucky[pivot]){
				sum+= lucky[pivot];
			}else{
				pivot = lower_bound(lucky.begin()+1, lucky.end(), i)- lucky.begin();
				sum+= lucky[pivot];
			}
		}
		cout << sum << endl;
	}
	return 0;
}


