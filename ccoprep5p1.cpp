#include <bits/stdc++.h>
using namespace std;
int T, N, M, height[1001], city[1001][1001], tallest;
stack<pair<int, int>> stk;
int getTallestTower(int r){
	int ans = 0;
	stk.push(make_pair(-1, -1));
	for(int i = 0; i < M; i++){
		while(stk.size() > 1 && stk.top().first >= city[r][i]){
			int a = stk.top().first;
			int b = stk.top().second;
			if(stk.size() > 1)stk.pop();
			ans = max(ans, a*(i - stk.top().second - 1 ));
		}
		stk.push(make_pair( city[r][i], i) ) ;
	}
	while(stk.size() > 1){
		int a = stk.top().first;
		int b = stk.top().second;
		if(stk.size() > 1) stk.pop();
		ans = max(ans, a*(M-1 - stk.top().second));
	}
			
	return ans;
}
int main(){
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> N >> M;
		tallest = 0;
		for(int i = 0; i< N; i++){
			for(int j = 0; j < M; j++){
				char a;
				cin >> a;
				if(a == 'F')
					city[i][j] = 1;
			}
		}
		tallest = max(tallest, getTallestTower(0));
		for(int i = 1 ; i < N; i++){
			for(int j = 0; j < M; j++){
				if(city[i][j] != 0){
					city[i][j] += city[i-1][j];
				}else city[i][j] = 0;
			}
			tallest = max(tallest, getTallestTower(i));
		}
		cout << 3*tallest << "\n";
			
		for(int i = 0; i < N; i++){
			memset(city[i], 0, sizeof(city[i]));
		}
	}

}