#include <bits/stdc++.h>

using namespace std;
int N, M;
map<int, vector<int>> recipe;
int items[300005];
int dfs(int u){
	
	if(recipe[u].empty()){
		return items[u];
	}
	int minn = INT_MAX-1;
	for(auto v : recipe[u]){
		int temp = dfs(v);
		if(temp < minn)minn = temp;
	}
	//cout << u << " "<<items[u]<< " "<<minn <<"\n";
	return minn + items[u];
	
}
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a, n;
		cin >> a >> n;

		for(int i = 0; i < n; i++){
			int b;
			cin >> b;
			recipe[a].push_back(b);
		}
	}
	for(int i = 1; i <= N; i++){
		int b;
		cin >> b;
		items[i] = b;
	}

	cout << dfs(1);
}