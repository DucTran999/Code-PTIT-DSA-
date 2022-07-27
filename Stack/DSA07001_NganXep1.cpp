#include<bits/stdc++.h>
using namespace std;

int main() {
	string command = "";
	stack<int> st;
	while(cin >> command){
		if(command == "push"){
			int x;
			cin >> x;
			st.push(x); 
		}else if(command == "pop" and !st.empty()){
			st.pop();
		}else{
			if(st.empty()){
				cout << "empty" << endl;
			}else{
				stack<int> tmp;
				while(!st.empty()){
					tmp.push(st.top());
					st.pop();
				}
				while(!tmp.empty()){
					cout << tmp.top() << " ";
					st.push(tmp.top());
					tmp.pop();
				}
				cout << endl;
			}
		}
	}
	
	return 0;
}
