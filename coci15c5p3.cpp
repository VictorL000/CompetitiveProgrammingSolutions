#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

ll N, K, ans;
ll an[100005];
const ll mod = 1e9+7;
ll choose[100005][60];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> K;
	choose[0][0] = 1LL;
	for(int n = 1; n <= N; n++){
		for(int k = 0; k <= K; k++){
			if(k == 0)choose[n][k] = 1LL;
			else choose[n][k] = choose[n-1][k] + choose[n-1][k-1];
			choose[n][k] %= mod;
		}
	}
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		an[i] = a;
	}
	sort(an, an+N);
	for(int i = K-1; i < N; i++){
		ans += an[i] * 1LL * choose[i][K-1];
		ans %= mod;
	}
	cout << ans << '\n';
}