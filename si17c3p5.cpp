#include <bits/stdc++.h>
using namespace std;
int N;
long long ans;
unordered_map<int, vector<pair<int, int>>> mp;
unordered_map<int, int> has;
bool ctrd[100002];
int size[100002];

void cdfs(int u, int p){
	size[u] = 1;
	for(auto a : mp[u])
		if(a.first != p && ctrd[a.first] == false){
			cdfs(a.first, u);
			size[u] += size[a.first];
		}
}

int centroid(int u, int p, int sz){
	for(auto a : mp[u])
		if(a.first != p && size[a.first]*2 > sz && ctrd[a.first] == false)
			return centroid(a.first, u, sz);
	return u;
}

void dfs(int u, int p, int sum, vector<int>& path){
	path.push_back(sum);
	ans += has[-sum-1];
	ans += has[-sum+1];	
	//	if(lastsum == -sum-1 || lastsum == -sum+1)ans--;
	//	cnt++;
	
//	cout << u << "cur " << p << "par " <<sum << "sum " << ans<< "ans \n";
	for(auto a:mp[u]){
		if(a.first != p && ctrd[a.first] == false)
			dfs(a.first, u, sum + a.second, path);
	}

	//has[sum]++;
}
void build(int u){
	cdfs(u, 0);
	int c =	centroid(u, 0, size[u]);
	ctrd[c] = true;
	//cout << c << " is centroid\n";
	has.clear();
	has[0] = 1;
	for(auto a : mp[c]){ //for all neighbors of c, run dfs
		if(ctrd[a.first] == false){
			vector<int> path;
			dfs(a.first, c, a.second, path);
			for(int x:path) has[x]++;
		}
	}
	for(auto a : mp[c]){
		if(ctrd[a.first] == false) build(a.first);	
	}
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N-1; i++){
		int a, b;
		char c;
		cin >> a >> b >> c;
		if( c == 'r'){
			mp[a].push_back(make_pair(b, 1));
			mp[b].push_back(make_pair(a, 1));
		}
		else{
			mp[a].push_back(make_pair(b, -1));
			mp[b].push_back(make_pair(a, -1));
		}
	}
	has[0] = 1;
	build(1);
	cout << "" << ans -N+1;
}