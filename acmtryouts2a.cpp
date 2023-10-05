#include "bits/stdc++.h"

using namespace std;

int N, T;

map<int, vector<int>> mp;

int dfs(int u, int steps){
	if(u == 91)return steps;
	int m = 0;
	for( auto i : mp[u] )
		m = max(m, i);
	return dfs(m, steps+1);
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	for(int i = 1; i <= 8; i++){
		for(int j = 1; j <=4; j++){
			int cur = 10*i + j;
			if(j == 4)
				mp[cur].emplace_back((i+1)*10 + 1);
			else
				mp[cur].emplace_back(cur+1);
		}
	}
	mp[12].emplace_back(41);
	mp[42].emplace_back(81);
	cin >> T;
	while(T--){
		char a, b, c;
		cin >> a >> b >> c;
		int lvl = (int(a)-'0')* 10 + (int(c)-'0');
		cout << dfs(lvl, 0) << '\n';
	}
}