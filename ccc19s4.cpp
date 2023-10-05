#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+3;
int N, K, a[MM], day[MM], pmx[MM], smx[MM]; 
ll dp[MM], t1[MM], t2[MM];

int main(){
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++){
		scanf("%d", &a[i]);
		day[i] = (i + K - 1)/K;
		if(day[i] != day[i-1]) pmx[i] = a[i];
		else pmx[i] = max(pmx[i-1], a[i]);
		}
	for(int i = N; i >= 1; i--){
		if(day[i] != day[i+1]) smx[i] = a[i];
		else smx[i] = max(smx[i+1], a[i]);
	}
	for(int i = 1; i <= K; i++)
		dp[i] = pmx[i];
	for(int d = 2; d <= day[N]; d++){
		int fst = K * (d-2)+1, lst = K * (d-1);
		for(int j = lst; j >= fst; j--){
			t2[j] = dp[j];
			t1[j] = dp[j] + (day[j+1] == day[j] ? smx[j+1] : 0);
			if(j != lst){
				t1[j] = max(t1[j], t1[j+1]);
				t2[j] = max(t2[j], t2[j+1]);
			}
		}
		for(int j = K*(d-1)+1; j <= min(N, K*d); j++)
			dp[j] = max(t1[j-K], t2[j-K] + pmx[j]);
	}
	printf("%lld\n", dp[N]);
}