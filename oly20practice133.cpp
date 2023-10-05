#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;

ll N, K;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	N %= K;
	cout << min(N, abs(N-K));
}