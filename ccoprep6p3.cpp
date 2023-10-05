#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N, Q, to[200005], js[200005], a[200005], sq;
void build(int start, int end){
	for(int i = start; i >= end; i--){
		if(a[i] >= (N-1 - i)){
		// hopped to end	
		}
		to[i] = a[i]+i;
		if(to[i] < N && to[i]/sq == i/sq)to[i] = to[to[i]];

		if(i+a[i] > N-1 || i/sq != (i+a[i])/sq )js[i] = 1;
		else js[i] = 1+js[a[i]+i];
	}

}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		int b;
		cin >> b;
		a[i] = b;
	}
	sq = sqrt(N);
	build(N-1, 0);

	cin >> Q;
	while(Q--){
		int op;
		cin >> op;
		if(op == 1){
			int x;
			cin >> x;
			int ans = 0;
			while(x < N){
				ans += js[x];
				x = to[x];
			}
			cout << ans << '\n';
		}
		else{
			int x, v;
			cin >> x >> v;
			a[x] = v;
			build(x, (x/sq)*sq);

		}
	}
}