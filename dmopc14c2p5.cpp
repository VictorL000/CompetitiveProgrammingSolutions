#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N, M;
vector<int> mp[1000010];
double ans[1000010];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 0 ; i < M; i++){
		int a, b;
		cin >> a >> b;
		mp[a].push_back(b);
	}
	ans[1] = (double) 1;
	for(int i = 1; i <= N; i++){
		if(mp[i].size() > 0 ){
			double p = ans[i]/mp[i].size();
			for(int j = 0; j < mp[i].size(); j++)
				ans[mp[i][j]] += p;
		}
	}
	for(int i = 1; i <= N; i++){
		if(mp[i].size() == 0)
			cout << setprecision(9) << ans[i] << '\n';
	}
}