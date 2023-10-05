#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

// without psa

int N, M, T;
double dp[2005][2005];
struct node{
	int to, lo, hi;
};

map<int, vector<node> > mp;

void solve(){
	/*
	for(int i = 1; i < N; i++){ // loop through all stations
		for(int t = 0; t < T; t++){
			for(auto it : mp[i]){
				int j = it.to;
				for(int x = it.lo; x <= it.hi; x++){
					if(x + t <= T){
						dp[x+t][j] += dp[t][j] * 1/mp[i].size() * 1/(it.hi-it.lo+1);
					}
				}
			}
		}
	}
	*/
	for(int t = 0; t < T; t++){
		for(int u = 1; u < N; u++){
			for(auto it : mp[u]){
				for(int k = it.lo; k <= it.hi; k++){
					if(k + t > T)break;
					dp[t+k][it.to] += (dp[t][u]/mp[u].size()) / (it.hi - it.lo + 1);
				}
			}
		}
	}
}

void bruceSolve(){
	for(int t = 0; t <= T; t++){
		for(int u =1; u <= N; u++){
			if(t > 0)dp[t][u] += dp[t-1][u];
			if(u == N)continue;
			for( node e : mp[u] ){
				int v = e.to;
				int l = e.lo;
				int h = e.hi;
				if(t + l > T) continue;
				double p = dp[t][u] / mp[u].size() / (h-l+1);
				dp[t + l][v] += p;
				dp[min(t + h, T)+1][v] -= p;
			}
		}
	}
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> M >> T;
	for(int i = 0; i < M; i++){
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		node n;
		n.to = b;
		n.lo = x;
		n.hi = y;
		mp[a].push_back(n);
	}
	dp[0][1] = (double)1;
	dp[1][1] = -1.0;
	bruceSolve();
//	solve();
	double num = 0, den = 0;
	for(int t = 1; t <= T; t++){
		num += t* dp[t][N];
		den += dp[t][N];
	}
	cout << fixed << setprecision(10) << num/den << '\n';

}