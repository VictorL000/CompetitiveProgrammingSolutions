#include <bits/stdc++.h>
using namespace std;
int N, K;
long long a[(1<<23) + 5], dp[(1<<23) + 5];
deque<pair<long long, long long>> qu;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> a[i];
	}
	qu.push_back({1LL*0, 0});
	for(int i = 1; i <= N; i++){
		dp[i] = qu.front().first + a[i];

		while(!qu.empty() && dp[i] <= qu.back().first){
			qu.pop_back();
		}

		qu.push_back({dp[i], 1LL*i});
		if(qu.front().second + K == i)qu.pop_front();
	}
	dp[N+1] = qu.front().first;
	cout << dp[N+1] << "\n";
	stack<int> ans;
	long long look = dp[N+1];
	for(int i = N; i > 0; i--){
		if(dp[i] == look){
			look -= a[i];
			ans.push(i);
		}
	}	
	while(!ans.empty()){
		cout << ans.top() << " ";
		ans.pop();
	}
	cout << "\n";
	return 0;
}