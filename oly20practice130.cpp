#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
const int MM = 1e5+2;
int N, n[100005];
long long psa[100005];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    long long sum = 0;
    for(int i = 0; i < N; i++){
      int a;
      cin >> a;
      n[i] = a;
      sum += a;
      psa[i+1] = sum;
    }
    long long ans = 99999999999;
    for(int i = 1; i < N; i++){
  //    cout << "i :" << i << '\n';
        long long left = psa[i];
        int lo = i;
        int hi = N;
        int mid = (lo + hi)/2;
    //    cout << left << '\n';
        for(int j = 0; j < 18; j++){
          mid = (lo + hi)/2;
          long long middle = psa[mid]-psa[i];
          long long right = psa[N]-psa[mid];
      //    cout << middle << "  " << right << "  " << '\n';
          ans = min(ans, max(left, max(middle, right)) - min(left, min(middle, right)));
          if(middle > right){
            hi = mid;
          }
          if(middle < right){
            lo = mid+1;
          }
          if(middle == right)break;
        }
    }
  cout << ans;
}