#include <bits/stdc++.h>

using namespace std;
int main() {
  int C, M, K;
  cin >> C >> M >> K;
  int ans = max(C*K, M*K);
  cout << ans << "\n";
}