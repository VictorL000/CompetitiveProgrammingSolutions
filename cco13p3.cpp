#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
int N, ep, eplen, dialen;
long long dias, dist[400005], val[400005];
map< int, vector<int> > mp;
void dfs(int u, int l, int p){
	if( l > eplen ){
		eplen = l;
		ep = u;
	}
	for(int i : mp[u]){
		if(i != p)dfs(i, l+1, u);
	}
}
void backtrack(int u, int p){
	bool leaf = true;
//	cout << "backtrack at " << u << "\n";
	for(auto i : mp[u]){
		if(i != p){
			leaf = false;
			backtrack(i, u);
			
		}
	}
	if(leaf){
		//cout << "leaf at " << u << "\n";
		val[u] = 1; dist[u] = 1;
		return;
	}
	long long vl, dst;
	vl = dst = 0;
	for(auto i : mp[u]){
		if(true){
			if(dst + dist[i] > dialen){
				dialen = dst+dist[i] ;
				dias = vl * val[i];
				//cout << "updated dias to " << dias <<  " with dialen " <<   dialen  << "\n";
				//error(u, i);
			}
			else if(dst + dist[i] == dialen){
				dias += vl * val[i];
				//cout << "incremented dias to " << dias <<  " with dialen " << dialen << "\n";
				//error(u, i);
			}
			if(dist[i] +1 > dst){
				//should update
				dst = dist[i] + 1;
				vl = val[i];
			}
			else if(dist[i] +1 == dst){
				vl += val[i];
			}
		}
	}
	dist[u] = dst;
	val[u] = vl;
	//cout<< u << ": \n ";
	//error(val[u] , dist[u]);
	
	
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	dias = 1;
	cin >> N;
	int start = 1;
	for(int i = 1; i < N; i++){
		int a, b;
		cin >> a >> b;
		start = a;
		mp[a].emplace_back(b);
		mp[b].emplace_back(a);
	}
	dfs(start, 0, 0);
	val[ep] = 1;
	dist[ep] = 1;
	backtrack(ep, 0);
	cout << dialen << " " <<dias;
}