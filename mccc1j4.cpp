#include <bits/stdc++.h>

using namespace std;
  char a[1000005];
  long long  l[1000005], r[1000005];
int main() {
  long long n;
  cin >> n;

  long long count = 1;
  cin >> a;
  long long onLeft = 0;
  for(long long i =0 ; i < n; i++){
    l[i] = LLONG_MAX-1;
    r[i] = LLONG_MAX-1;
  }
  for(long long i = 0; i < n; i++){
    if(a[i] == '1'){
      onLeft = i;
      break;
    }
  }
  for(long long i = onLeft; i < n; i++){

    if(a[i] == '1')count = 0;
    else count++;
    l[i] = count;
  }
  long long onRight = n;
  for(long long i = n-1; i >= 0; i--){
    if(a[i] == '1'){
      onRight = i;
      break;
    }
  }
  count = 1;
  for(long long i = onRight; i >= 0; i--){
    if(a[i] == '1')count = 0;
    else count++;
    r[i] = count;

  }
  long long ans = 0;
  for(long long i =0 ; i< n ;i++){
    ans += min(l[i], r[i]);
  }
  for(long long i =0 ; i< n ;i++){
//     cout <<l[i] << " ";
  }
  cout << ans<<"\n";
  for(long long i =0 ; i< n ;i++){
//     cout <<r[i] << " ";
  }

}