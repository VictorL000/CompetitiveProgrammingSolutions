#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;

ll N, K;
int main(){
	cin >> N >> K;
	ll ans = 1;
	while(N--)ans *= K;
	cout << ans;
}