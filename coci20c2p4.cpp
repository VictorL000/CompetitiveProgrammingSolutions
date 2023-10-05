#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, hardness[100005];
ll ans = 0LL;
int lg = 0;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		int a;
		cin >> a;
		hardness[i] = a;
		lg = min(lg, -hardness[i]);
		ans += hardness[i];
	}
	ans += lg;
	for(int i = 1; i < N; i++){
		int a, b;
		cin >> a >> b;
		ans += max(hardness[a], hardness[b]);
	}
	cout << ans << '\n';
}