#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
//pls dont read im just testing partial solution :(
int N, M;
long long ans;
priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>> > pq;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> M;
	long long last = 0;
	while(N--){
		int a;
		long long b;
		cin >> a >> b;
		pq.push({a, b});
	}
	while(!pq.empty()){
		pair<int, long long> cur = pq.top();
		pq.pop();
		ans += max(0LL, cur.second - last);
		last = cur.second;
	}
	cout << ans << '\n';
}