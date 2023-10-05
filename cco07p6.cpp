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
int N, K, id[1005], low[1005], ans, cnt, pnt[1005];

bool onstack[1005], vis[1005];
stack<int> st;
map<int, vector<int> > imp, mp, scc, roots;
void dfs(int u, int p){
	if(vis[u])return;
	vis[u] = true;
	for(auto i :imp[u]){
		if(i != p){
			mp[u].emplace_back(i);
			dfs(i, u);
		}
	}
}
void tarjan(int u){
	cnt++;
	id[u] = cnt;
	low[u] = cnt;
	st.push(u);
	onstack[u] = true;
	for(auto i : mp[u]){
		if(id[i] == 0){
			tarjan(i);
			low[u] = min(low[u], low[i]);
		}
		if(onstack[i]){
			low[u] = min(low[u], id[i]);
		}
	}
	if(id[u] == low[u]){
		while(true){
			int c = st.top();
			onstack[c] = false;
			pnt[c] = u;
//			cout << "parent of " << c << " is " << u << '\n';
			st.pop();
			roots[u].emplace_back(c);
			if( c == u )break;
		}

	}
}

void simp(){
	for(auto kv: roots){
		int key = kv.first;
		set<int> invec, b;
		for(auto i : kv.second){
//			cout << "iterate through " << kv.first << "\n";
			for(auto j : mp[i]){
//				cout << "iterate through mp[" << i << "]\n";
//				error(i, j);
//				error(pnt[i], pnt[j]);
				if(pnt[j] != pnt[i]){
					invec.insert(pnt[j]);
					b.insert(pnt[j]);
//					cout << j << " was inserted into " << pnt[i] << '\n';
				}
			}
		}
		for(int i : invec){
			scc[key].emplace_back(i);
//			cout << key << " : " << i <<'\n';
		}
		for(int i : b){
			scc[i].emplace_back(key);
//			cout << i << " : " << key <<'\n';
		}
	}
	//iterate through all keys of root
	//iterate through all child of the values
	//if pnt[child]  != pnt[root], set.emplace_back(pnt[child])
	//after finish iterating though child, loop through set elements, scc.emplace_back(set.top);
}
void dfs2(int u, int p){
	if(u == p)return;
	int cntt =  0;
	for(auto i : scc[u]){
		cntt++;
		if( i != p ){
			dfs2(i, u);
		}
	}
	if(cntt == 1)ans++;

}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	while(K--){
		int a, b;
		cin >> a >> b;
		imp[a].emplace_back(b);
		imp[b].emplace_back(a);
	}
	dfs(1, 1);
	memset(vis, false, N+1);
	tarjan(1);
	simp();
	dfs2(1, 0);
	cout << (ans+1)/2 ;
}