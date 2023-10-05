#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;

int N, M;
int h[1000005], psa[1000005];
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		h[a]++;
	}
	psa[0] = h[0];
	for(int i = 1; i < 1000005; i++){
		psa[i] = h[i] + psa[i-1];
	}
	while(M--){
		int a;
		cin >> a;
		cout << max(0, N-psa[a-1]) << '\n';
	}
}