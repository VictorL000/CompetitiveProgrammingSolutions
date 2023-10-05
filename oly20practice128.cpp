#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N, T, M, a[100005];
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> T >> M;
	for(int i = 0; i < M; i++){
		int g;
		cin >> g;
		a[g-1]++;
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		if(T+a[i]-M > 0)ans++;
	}
	cout << ans << '\n';
}