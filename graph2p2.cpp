#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N, id[1005], low[1005], cnt;

bool instack[1005];
stack<int> stk;
map<int, vector<int>> mp;
bool ans;
void tarjan(int u){
	cnt++;
	id[u] = low[u] = cnt;
	stk.push(u);
	instack[u] = true;
	for(auto i : mp[u]){
		if(id[i] == 0){
			tarjan(i);
			low[u] = min(low[u], low[i]);
		}
		if(instack[i]){
			low[u] = min(low[u], id[i]);
		}
	}
	if(id[u] == low[u]){
		while(1){
			int c = stk.top();
			instack[c] = false;
			stk.pop();
			if(c != u){
				ans = false;
				return;
			}
			if(c == u)break;
		}
	}

}
int main(){
	ans = true;
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	int root = 0;
	int a;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> a;
			if(a == 1){
				mp[i+1].emplace_back(j+1);
				root = i+1;
			}
		}
	}
	tarjan(root);
	cout << (ans?"YES":"NO");
}