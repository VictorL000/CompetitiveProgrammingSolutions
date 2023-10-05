#include <bits/stdc++.h>
using namespace std;
int N, a[500005], b[500005], psa[652][652];
int main() {
  int up = 651;
  scanf("%d", &N);
  
  for(int i = 1; i <= N; i++){
    scanf("%d %d", &a[i], &b[i]);
    a[i]++;
    b[i]++;
    psa[a[i]][b[i]]++;
  }

  for(int i = 1; i <= up; i++)
    for(int j = 1; j <= up; j++)
      psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];

  for(int i = 1; i <= N; i++){
    int x = a[i];
    int y = b[i];
    int best = psa[up][up] - psa[x][up] - psa[up][y] + psa[x][y];

    int worst = psa[x-1][y-1];

    if(x == up) worst += psa[1][y] - psa[1][y-1];
    if(y == up) worst += psa[x][1] - psa[x-1][1];

    printf("%d %d\n", best+1, N-worst);
  }
  
}