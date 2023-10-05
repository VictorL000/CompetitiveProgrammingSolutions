#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N, mod;
long long down[100005];
vector<long long> val[100005], pre[100005], suf[100005];
map<int, vector<int>> mp;
void dfs(int u, int p){
	down[u] = 1;
	val[u].push_back(1LL);
	for(auto i : mp[u]){
		if(i != p){
			dfs(i, u); 
			down[u] *= down[i] % mod+1;
			down[u] %= mod;
			val[u].push_back(1LL *(down[i] % mod + 1) % mod);
		}
		else val[u].push_back(-1LL);
	}
}
void dfs1(int u, int p, long long pass){
	//build pre and suf
	pre[u].push_back(val[u][0]* 1LL % mod);
	for(auto& i : val[u]){
		if( i == -1 )i = 1LL * pass+1;
		i %= mod;
		i *= 1LL;
	}
	for(int i = 0; i < (int)val[u].size(); i++){
		if(val[u][i] == -1)val[u][i] = (pass * 1LL + 1) % mod;
		if(i != 0)
			pre[u].push_back((val[u][i] % mod * pre[u][i-1]  % mod* 1LL) % mod);
	}
	pre[u].push_back(1 * 1LL);
	pre[u].push_back(1LL);
	long long prod = 1LL;
	for(int i = (int)val[u].size()-1; i >= 0; i--){
		if(val[u][i] <= -1)cout << "not supposed to happen";
		prod *= val[u][i] % mod * 1LL;
		prod %= mod;
		prod *= 1LL;
		suf[u].push_back(prod % mod);
	}
	reverse(suf[u].begin(), suf[u].end());
	suf[u].push_back(1LL);
	suf[u].push_back(1LL);
	for(int i = 0; i < (int) mp[u].size(); i++){
		if(mp[u][i] != p){
			long long ps = (pre[u][i] % mod * suf[u][i+2]  % mod* 1LL) % mod;
//			cout << ps << " was passed from " << u << " to " << mp[u][i] << '\n';
			dfs1(mp[u][i], u, ps);
		}
	}
	/*
	cout << u << " :\n";
	for(int a : pre[u]){
		cout << a << ' ';
	}
	cout << '\n';
	for(int a : suf[u]){
		cout << a << ' ';
	}
	cout << '\n';
	*/
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> mod;
	for(int i = 1; i < N; i++){
		int a, b;
		cin >> a >> b;
		mp[a].emplace_back(b);
		mp[b].emplace_back(a);
	}
	dfs(1, 0);
	dfs1(1, 0, 1);
	for(int i = 1; i <= N; i++)
		cout << suf[i].front() << '\n';
}