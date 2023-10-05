#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, Q, h[MM];
stack<int> stk;
long long psa[MM];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> Q;
  for(int i = 1; i <= N; i++) cin >> h[i];
  for(int i = 1; i <= N; i++){
    while(!stk.empty() && h[i] < h[stk.top()]){
        int idx = stk.top(); stk.pop();
        int lft = stk.empty() ? 0 : stk.top();
        int rit = i;
        psa[h[idx]] += 1LL*(idx - lft) * (rit-idx);
    }
    stk.push(i);
  }
  while(!stk.empty()){
    int idx = stk.top(); stk.pop();
    int lft = stk.empty() ? 0 : stk.top();
    int rit = N+1;
    psa[h[idx]] += 1LL*(idx - lft) * (rit-idx);
  }
  for(int i = 1; i < MM; i++) psa[i] += psa[i-1];
  for(int i = 1, x, y; i<= Q; i++){
    cin >> x >> y;
    cout << (psa[y] - psa[x-1]) << "\n";
  }
}