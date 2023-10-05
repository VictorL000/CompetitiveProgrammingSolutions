#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pos;
priority_queue<int> neg;
int N, ans;
long long T;
int main() {
  cin >> T >> N;
  for(int i = 0; i < N; i++){
    int a;
    cin >> a;
    if( a > 0){
      pos.push(a);
    }
    else
      neg.push(a);
  }
  long long elapse = 0;
  int x = 0;
  for(int i = 0; i < N; i++){
    int p = pos.top();
    int n = neg.top();
    if(!pos.empty() && (abs(p) < abs(n) || neg.empty())){ //closer to p
 //   cout << p << "p\n";
      elapse += abs(x-p);
      if(elapse > T)
        break;
      ans++;
      x = p;
      pos.pop();
    }else {
   //   cout << n << "n\n";
      elapse += abs(x-n);
      if(elapse > T)
        break;
      ans++;
      x = n;
      neg.pop();
    }

  }
    cout << ans << " ";

}