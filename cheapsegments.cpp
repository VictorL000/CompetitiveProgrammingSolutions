#include <bits/stdc++.h>
using namespace std;	

int N, l[100001], r[100001], v[100001], Q, sparse[300001][30], depth[100001], lookup[100001];
priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int> > > pq;
map<int, vector<int>> mp;
map<int, int> parent;

bool tupleCompare(tuple<int, int, int, int> a, tuple<int, int, int, int> b){
	if(get<0>(a) < get<0>(b))
		return true;
	return false;
}
bool sterile[100001];
int abc = 0;
void dfs(int u, int dep){
	depth[u] = dep;
	sparse[abc][0] = u;
	abc++;
	for(int j : mp[u]){
		dfs(j, dep+1);
		sparse[abc][0] = u;
		abc++;
	}
	if(mp[u].empty()){
		sparse[abc][0] = u;
		abc++;
	}
}

int main(){
	vector<int> temp;
	mp[-1]= temp;
	scanf("%d", &N);
	int curNode = -1;
	for(int i = 0; i < N; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		pq.push(make_tuple(a, b, c, i+1));
	}
	for(int i = 0; i < N; i++){
	//	cout << get<0>(pq.top())<<get<1>(pq.top())<<get<2>(pq.top()) << "\n";
	//	pq.pop();
	}
	
	for(int j = 0; j < N; j++){
		int _l, _r, _v, i;
		tie(_l, _r, _v, i) = pq.top();
		pq.pop();
		
		l[i]=_l;
		r[i]=_r;
		v[i]=_v;
	//	cout << _l << " "<<_r<<" "<<_v<<"\n";
		while(true){
			if(curNode == -1){
				mp[-1].push_back(i);
				parent[i] = -1;
				curNode = i;
				//cout << "inserted "<<i<< "\n";
				break;
			}
			else{
				//cout << "DEBUG: " << i << " " << curNode << " " << _r << " " << r[curNode] << " " << _v << " " << v[curNode] << "\n";;
				if(_r < r[curNode] && !sterile[curNode]){
				//	cout << "inserted "<<i<< "\n";
					if(_v > v[curNode]){
						sterile[i] = true;
					//	cout << "sterilized "<<i<<"\n";
					}
					mp[curNode].push_back(i);
					parent[i] = curNode;
					if(sterile[i] == false)
						curNode = i;
					break;
				}
				else{
					//cout << "not suitable for parent\n";
					curNode = parent[curNode];
				}
			}
		}	
	}
//	for(int i = -1; i <= N; i++){
//		cout << i << ": ";
//		for(int j : mp[i])
//			cout << j << ", ";
//		cout << "\n";
//	}
	dfs(-1, 0);	
	//cout << abc << " < abc \n";
	for(int i = 0; i < abc; i++){
//		cout << sparse[i][0] << " ";
		if(sparse[i][0] != -1)
			if(lookup[ sparse[i][0] ] == 0)
				lookup[sparse[i][0]] = i;
	}
//	cout << "\n";
	for(int i = 1; i < 31; i++){
		for(int j = 0; j < abc - (1<<i)+1; j++){
			if(depth[sparse[j][i-1]] < depth[sparse[j+ (1 << (i-1)) ][i-1]] )
				sparse[j][i] = sparse[j][i-1];
			else sparse[j][i] = sparse[j + (1 << (i-1))][i-1];
//			cout << sparse[j][i] << " ";
		}
//		cout << "\n";
	}
	
	scanf("%d", &Q);
//	for(int i = 1; i<= N; i++)
//		cout << " " << lookup[i];
//	cout << "\n";
	for(int i = 0; i < Q; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		int dist = floor( log2(abs(lookup[a] - lookup[b])) ); 
//		cout << dist << " is the distance \n";
		int ans;
		if(depth[sparse[ min(lookup[a], lookup[b])][dist]] <
			      depth[sparse[ max(lookup[a], lookup[b])-(1<<dist)+1][dist]])
			ans = sparse[ min(lookup[a], lookup[b])][dist];
		else ans = sparse[ max(lookup[a], lookup[b])-(1<<dist)+1][dist];
//		cout << ans<<"\n";
		if(ans == a || ans == b)
			ans = parent[ans];
		
		printf("%d\n", ans);

//		cout << (min(lookup[a], lookup[b])) << "\n"; 
//		cout << (max(lookup[a], lookup[b])-(1<<dist)+1) << "\n";
	}
		
}