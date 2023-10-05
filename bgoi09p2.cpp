#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N, pnt[100005], ans;

map<int, vector<int> > ds;
int find_set(int v){
	if(pnt[v] == v)return v;
	return pnt[v] = find_set(pnt[v]);
}
void union_set(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b){
		pnt[b] = a;
		ans--;
	} 
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	for(int j = 0; j < 2; j++){
		memset(pnt, 0, 100005);
		cin >> N;
		ans = N;
		for(int i = 1; i <= N; i++)pnt[i] = i;
		for(int  i = 1 ; i <= N; i++){
			int a;
			cin >> a;
			union_set(i, a);
		}
		if(j == 0)cout << ans << " ";
	}
	cout << ans;
}