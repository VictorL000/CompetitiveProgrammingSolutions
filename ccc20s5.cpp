#include <bits/stdc++.h>

using namespace std;
const int MM = 1e6+5;
int N, b[MM], lst[MM];
double dp[MM], sum;
int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
      scanf("%d", &b[i]);
    }
    dp[N] = (b[N] == b[1]? 1.0 : 0.0);
    lst[b[N]] = N;
    sum += dp[N];
    for(int i = N-1; i >= 1; i--){
      if(b[i] == b[1]) dp[i] = 1.0;
      else if(lst[b[i]] != 0) dp[i] = dp[lst[b[i]]];
      else dp[i] = (1+sum)/(N-i+1);
      lst[b[i]] = i;
      sum += dp[i];
    }
    printf("%.9f\n", sum/N);
}