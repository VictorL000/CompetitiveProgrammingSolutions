#include <bits/stdc++.h>
using namespace std;
int N, M, ans;
int best[100005];
int indeg[100005];
queue<int> zeroin;
vector<int> topsorted;
map<int, vector<int>> mp, topo;
#define max(a, b) a>b?a:b
/*
int dfs(int u, int len){
	if(mp[u].empty())
		return len;
	int ret = -1;
	if(best[u] >= len && best[u] != 0)
		return best[u];
	
	best[u] = len;
	
	for(auto i : mp[u]){
		int t = dfs(i, len+1);
	//	cout << ret << " vs "<<t << "\n";
		ret = max(ret, t);
	//	cout << ret << " is larger\n";
	}

	return ret;
}
*/
int dist(int v){
return v;
}

int main(){
	scanf("%d%d", &N, &M);
	ans = 0;
	//memset(best, -1, 100000);	
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		mp[a].push_back(b);
		indeg[b]++;
		topo[b].push_back(a);
	}
	for(int i = 1; i <= N; i++)
		if(topo[i].empty()){
			zeroin.push(i);
			topsorted.push_back(i);
		}
	
	while(!zeroin.empty()){
		int a = zeroin.front();
		zeroin.pop();
		for(auto i : mp[a]){
		//	cout << i << " " << indeg[i]-1 << "\n";;
			indeg[i]--;
			if(indeg[i] == 0){
				zeroin.push(i);
				topsorted.push_back(i);
			}
		}
	}
	for(int i = 0; i < N; i++){
		int cur = topsorted[i];
		for(int a : mp[cur]){
			best[a] = max(best[a], best[cur]+1);
		}
		ans = max(ans, best[cur]);
	}
	printf("%d", ans);
}