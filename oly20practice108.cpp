#include "bits/stdc++.h"
using namespace std;
int N, M, a[100005];
int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	int ans = 1;
	set<int> st;
	for(int i = 0; i < N; i++){
		st.insert(a[i]);
		if((int)st.size() == M){
			ans ++;
			st.clear(); 
		}
	}
	cout << ans;
}