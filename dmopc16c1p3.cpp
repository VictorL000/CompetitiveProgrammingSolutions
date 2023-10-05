#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, a[100005];
double dp[100005];
double gdp(int i){
	if(i < 0)return 0;
	return dp[i];
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> a[i];
		a[i] *= 1.0;
	}
	dp[0] = a[0];
	for(int i = 1; i < N; i++){
		double dont_take = dp[i-1] + a[i];
		double take_2 = gdp(i-2) + 0.5 * min(a[i-1], a[i]) + max(a[i-1], a[i]);

		double take_3 = 99999999.0;
	        if(i >= 2)take_3 = gdp(i-3) + a[i] + a[i-1] + a[i-2] - min(min(a[i], a[i-1]), a[i-2]);
		dp[i] = min( min( dont_take, take_2), take_3);
	}
	printf("%.1f\n", dp[N-1]);
}