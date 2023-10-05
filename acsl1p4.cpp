#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N, K, ans;
bool vis[100];
int root[100];
map<int, vector<int>> mp, revmp;
stack<int> order;
set<int> players;
void dfs1(int u){
	if(vis[u])return;
	vis[u] = true;
	for(auto i : mp[u]){
		dfs1(i);
	}
	order.push(u);
}
void dfs2(int u, int p){
	if(vis[u]){return;}
	vis[u] = true;
	root[u] = p;
	bool flag = false;
	for(auto i : revmp[u]){
		if(root[i] == p)flag = true;
		if(vis[i] == false){
			flag = true;
			
			dfs2(i, p);
		}
	}
	if(flag)ans++;
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		players.insert(a);
		players.insert(b);
		if(c > d){
      		// a wins
			mp[a].emplace_back(b);
			revmp[b].emplace_back(a);
		}else{
			mp[b].emplace_back(a);
			revmp[a].emplace_back(b);
		}
	}
	for(auto i : players){
		dfs1(i);
	}
	memset(vis, false, 99);
	while(!order.empty()){
		dfs2(order.top(), order.top());
		order.pop();
	}
	cout << ans <<'\n';
}