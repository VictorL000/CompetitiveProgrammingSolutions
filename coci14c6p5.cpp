#include <bits/stdc++.h>
using namespace std;
int R, C, a[1001][1001], ans, hist[1001];

int maxHist(int h[]){
  stack< int > stk;
  int area = 0;
  for(int i = 0; i < C; i++){
    while(!stk.empty() && h[i] <= h[stk.top()]){
      int idx = stk.top();
      stk.pop();
      int rit = i;
      int lft = stk.empty() ? -1:stk.top();
      area = max(area, (rit-lft) * (h[idx]+1));
    }
    stk.push(i);
  }
  while(!stk.empty()){
    int idx = stk.top();
    stk.pop();
    int rit = C;
    int lft = stk.empty() ? -1:stk.top();
    area = max(area, (rit-lft) * (h[idx]+1));
  }
  return area;
}
int main() {
  cin >> R >> C;
  for(int i = 0; i < R; i++){
    for(int j = 0; j < C; j++){
      cin >> a[i][j];
    }
  }
  for(int i = 0; i < R-1; i++){
    for(int j = 0; j < C-1; j++){
      if(a[i][j] + a[i+1][j+1] <= a[i][j+1] + a[i+1][j])
        hist[j]++;
      else hist[j] = 0;
    }
    ans = max(ans, maxHist(hist));
  }
  cout << ans;
}