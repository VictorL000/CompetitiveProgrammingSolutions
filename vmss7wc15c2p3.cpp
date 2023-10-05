#include <bits/stdc++.h>
using namespace std;
int N;
stack<pair<long long, long long >> st;
long long a[400005], ans;
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	for(int i = 0; i < N; i++){
		if(st.empty()){
			st.push(make_pair(a[i], 1));
		}
		else{
			while(!st.empty() && a[i] > st.top().first){
				ans += st.top().second;
				st.pop();
			}
			if(!st.empty() && a[i] == st.top().first){
				int q = st.top().second;
				st.pop();
				ans += !st.empty();
				st.push(make_pair(a[i], q+1));
				ans += q;
			}
			else{
				ans += !st.empty();
				st.push(make_pair(a[i], 1));
			}
		}
	}
	cout << ans;
}