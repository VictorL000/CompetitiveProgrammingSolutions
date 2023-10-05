#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, K, cs[6000006];
ll psa[6000006], ans;

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		int m, x;
		cin >> m >> x;
		cs[x] = m;
	}
	psa[0] = cs[0];
	for(int i = 1; i < 6000006; i++){
		psa[i] = psa[i-1] * 1LL + cs[i] * 1LL;
	}
	for(int i = 0; i <= 1000000; i++){
		if(i-K-1 < 0)
			ans = max(ans, psa[i+K]);
		else
			ans = max(ans, psa[i+K] - psa[ i-K-1 ]);
	}
	cout << ans << '\n';
}