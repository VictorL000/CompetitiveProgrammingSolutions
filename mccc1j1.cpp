#include <bits/stdc++.h>

using namespace std;
int main() {
  priority_queue<int> pq;
  for(int i = 0; i < 4; i++){
    int a;
    cin >> a;
    pq.push(a);
  }
  int b = pq.top();
  pq.pop();
    pq.pop();
      pq.pop();
      cout << pq.top() << "\n" << b << "\n";


}