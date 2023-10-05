#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> mp;
int N, L, s, e;
bool vis[1000];
int main(){
	cin >> L >> s >> e >> N;
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		mp[a].push_back(b);
	}
	queue<pair<int, int>> qu;
	qu.push(make_pair(s, 0));
	int ans = 0;
	while(!qu.empty()){
		pair<int, int> cur = qu.front();
		qu.pop();
	 	vis[cur.first] = true;	
		if(cur.first == e){
			cout << cur.second; 
			return 0;
		}
		ans++;
		for(auto a : mp[cur.first]){
			if(!vis[a])
				qu.push(make_pair(a, cur.second+1));
		}
	}
	cout << -1;
}