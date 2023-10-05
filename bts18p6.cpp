#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, T;
long long da[MM], db[MM], dc[MM];
int main() {
  scanf("%d %d", &N, &T);
  for(int i = 1, x, y, a, b, c; i <= N; i++){
    scanf("%d%d%d%d%d", &x, &y, &a, &b, &c);
    long long va = a;
    long long vb = b - 2LL*a*x;
    long long vc = (long long) a * x * x - b * x + c;
    da[x] += va;
    db[x] += vb;
    dc[x] += vc;
    da[y+1] -= va;
    db[y+1] -= vb;
    dc[y+1] -= vc;
  }
  for(int i = 1; i <= T; i++){
    da[i] += da[i-1];
    db[i] += db[i-1];
    dc[i] += dc[i-1];
    printf("%lld ", da[i]*i * i + db[i] * i  + dc[i]);
  }
}