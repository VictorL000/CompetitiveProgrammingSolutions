#include <bits/stdc++.h>
using namespace std;
int N, Q;
long long dp[100004];
long long money[100004];
map<int, int> order;
vector<pair<long long, int>> q;
int ans[100004];
int main(){
	cin >> N >> Q;
	cin.tie(0);
	cin.sync_with_stdio();
	for(int i = 1; i <= N; i++){
		long long a;
		cin >> a;
		money[i] = a;
	}
	for(int i = 1; i <= N; i++){
		int a;
		cin >> a;
		order[i] = a;
	}
	
	for(int i = 0; i < Q; i++){
		long long p, c;
		cin >> p >> c;
		q.push_back(make_pair(c-p, i));
	}
	long long maxn = -1;
	for(int i = 1; i <= N; i++){
		dp[i] = dp[ order[i] ] + money[i];
		maxn = max(dp[i], maxn);
	//	cout << dp[i] << " ";
	}	
	
	sort(q.begin(), q.end());
	int cur = 0;
	for(int i = 1; i <= N && cur < Q; i++){
		pair<long long, int> curQ = q[cur];
	//	cout << curQ.first <<" in dollars"<< dp[i]  << " \n";
		if(curQ.first <=0 || curQ.first > maxn){
			ans[curQ.second] = -1;
			cur++;
			i--;
			continue;
		}
		if(dp[i] >= curQ.first){
			ans[curQ.second] = i;
			cur++;
			i--;
			continue;
			
		}
	}	
	for(int i = 0; i < Q; i++)
		cout << ans[i] << "\n";

}