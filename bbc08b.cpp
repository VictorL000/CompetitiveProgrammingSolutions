#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, LOG = 17, MN = 1e6+5;
const long long MOD = 1e9+7;
int N, K;
int costFrom[MM], costTo[MM], lcaSparse[LOG][MM], dep[MM], firstSaw[MM];
long long finalAns, pow2[MN], up[MM], down[MM];

vector<pair<int, int>> mp[MM];

void dfs(int u, int p){
	dep[u] = dep[p]+1;
	lcaSparse[0][u] = p;
	for(auto e : mp[u]){
		if(e.first != p)
			dfs(e.first, u);
	} 
}

int getlca(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = LOG-1; i >= 0; i--){
        if(~lcaSparse[i][u] and dep[lcaSparse[i][u]] >= dep[v])
            u = lcaSparse[i][u];
    }
    if(u == v)
        return u;
    for(int i = LOG-1; i >= 0; i--){
        if(~lcaSparse[i][u] and ~lcaSparse[i][v] and lcaSparse[i][u] != lcaSparse[i][v]){
            u = lcaSparse[i][u];
            v = lcaSparse[i][v];
        }
    }
    return lcaSparse[0][u];
}
void lastDFS(int cur, int pre, int t){
	for(auto e : mp[cur]){
		if(e.first == pre)
			continue;

		lastDFS(e.first, cur, e.second);
		up[cur] += up[e.first];
		down[cur] += down[e.first];
	}
	if( t == 1 ){
		finalAns += pow2[up[cur]]-1;
		finalAns %= MOD;
	}
	if(t == 2){
		finalAns += pow2[down[cur]]-1;
		finalAns %= MOD;
	}
}
int main(){
	memset(lcaSparse, -1, sizeof lcaSparse );
	pow2[0] = 1;

	for(int i = 1; i < MN; i++)
		pow2[i] = pow2[i - 1] * 2 % MOD;
	scanf("%d", &N);

	for(int i = 0; i< N-1; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		mp[a].push_back(make_pair(b,c));
		mp[b].push_back(make_pair(a,2*c));
	}
	dfs(1, 0);
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= N; j++){
			if(~lcaSparse[i-1][j]) // if 0
					lcaSparse[i][j] = lcaSparse[i-1][lcaSparse[i-1][j]];
		}
	}
//	dfsCosts(1, 0, 0);

	scanf("%d", &K);
	int last = 1;
	for(int i =0; i < K; i++){
		int to;
		scanf("%d", &to);
		down[to]++;
		down[getlca(to, last)]--;
		up[last]++;
		up[getlca(to, last)]--;
		last = to;
	}
	lastDFS(1, 0, 0);
	cout << finalAns << "\n";
	return 0;
}