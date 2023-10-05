#include "bits/stdc++.h"
using namespace std;
int N;
bool up;
stack<int> st;
int main(){
	cin >> N;
	while(N--){
		int a;
		cin >> a;
		if(st.size() < 2){
			if(st.size() == 1){
				if(a > st.top())
					up = true;
				else if(a == st.top())
					st.pop();
				else	up = false;
			}
			st.push(a);
		}else{
			if( up ){
				if(a > st.top()){
					//replace top
					st.pop();
					st.push(a);
				}
				else if (a < st.top()){
					st.push(a);
					up = false;
				}
			}
			else{
				if(a < st.top()){
					//replace top
					st.pop();
					st.push(a);
				}
				else if (a > st.top()){
					st.push(a);
					up = true;
				}

			}
		}
	}
	cout << st.size();
}