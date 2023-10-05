#include <bits/stdc++.h>
using namespace std;
bool sub[100000];
map<int, vector<int>> mp;
int N, K, ans;
vector<int> pho;
int dist[100000];
void mark(int cur, int last){
	for(auto it = mp[cur].begin(); it < mp[cur].end(); it++){
		int u = *it;
		if(u != last){
			mark(u, cur);
			if(sub[u])
				sub[cur] = true;
			
		}
	}
}

int dia1(int cur, int last, int len){
	int ret = -1;
//	cout << cur << " cur\n";	
	int children = 0;
	for(auto it = mp[cur].begin(); it < mp[cur].end(); it++){
		int u = *it;
		if(sub[u] && u != last){
			children++;
			ret = max(ret, dia1(u, cur, len+1));
		}
	}
	
	if(children == 0){
		dist[cur] = len;
		return len;
	}
	return ret;
}

int main(){
	ans = -2;
	cin >> N >> K;
	for(int i = 0; i < K; i++){
		int a; cin >> a;
		sub[a] = true;
		pho.push_back(a);
	}

	for(int i = 0; i < N-1; i++){
		int a, b; cin >> a >> b;

		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	mark(pho[0], -1);
	for(int i = 0; i < N; i++)
		if(sub[i]){
			//cout << i << " ";	
			ans+=2;
		}

//	cout << dia1(pho[0], -1, 0) << " len\n";	
	dia1(pho[0], -1, 0);
	int maxn = 0;
	for(int i = 0; i < N; i++)
		if(dist[maxn] < dist[i])
			maxn = i;
	dia1(maxn, -1, 0);
	maxn = -1;
	for(int i = 0; i < N; i++)
		maxn = max(maxn, dist[i]);	
	cout << ans - maxn ;
}