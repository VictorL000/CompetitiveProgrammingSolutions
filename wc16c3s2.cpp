#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, M, gym[200005], best, lvl;
ll ans = 0LL;
bool vis[200005];
map<int, vector<pi> > mp;
priority_queue<pi, vector<pi>, greater<pi> > next_edge;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		cin >> gym[i];
	}
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		mp[a].push_back({b, c});
		mp[b].push_back({a, c});
	}
	for(auto it : mp[1]){
		int to = it.first;
		int w = it.second;
		next_edge.push({w, to});
	//	cout << " ADDED EDGE TO " << to <<", REQUIRED LVL: " << w << '\n';
	}
	best = gym[1];
	lvl = 1;
	int cur = 1;
	vis[1] = true;
	while(!next_edge.empty() ){
		int t = next_edge.top().second;
		int req = next_edge.top().first;
		next_edge.pop();
		if(vis[t])continue;
		if(lvl < req){
			ans += 1LL*(req - lvl) * (1LL*best);
			lvl = req ;
		}
		cur = t;
		vis[cur] = true;
	//	cout << "NOW AT TOWN " << cur << "\n";

		best = min(best, gym[t]);
//		cout << "ans currently is " << ans << '\n';
//		cout << "lvl currently is " << lvl << '\n';
//		cout << "best gym currently is " << best << '\n'; 
		if(cur == N){
			cout << ans << '\n';
			return 0;
		}
		for(auto it : mp[t]){
			int to = it.first;
			if(vis[to])continue;
			int w = it.second;
			next_edge.push({w, to});
	//		cout << " ADDED EDGE TO " << to <<", REQUIRED LVL: " << w << '\n';
		}

	}
	cout << -1 << '\n';
}