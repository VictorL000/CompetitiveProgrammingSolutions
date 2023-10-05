#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N, Q, n[200005], a[500][200005];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> Q;
	for(int i = 0; i < N; i++){
		int b;
		cin >> b;
		n[i] = b;
	}
	int sq = sqrt(N);
	for(int i = 0; i < N; i++){
		int block = i/sq;
		for(int j = 1; j*j <= n[i]; j++){
			if(n[i] % j == 0){
				a[block][j]++;
				if(n[i] / j != j)
					a[block][n[i]/j] ++ ;
			}
		}
	}
	while(Q--){
		int op;
		cin >> op;
		if(op == 2){
			int u, v;
			cin >> u >> v;
			u--;
			int block = u/sq;
			for(int j = 1; j*j <= n[u]; j++){
				if(n[u] % j == 0){
					a[block][j]--;
					if(n[u]/j != j)
						a[block][n[u]/j]--;
				}
			}
			n[u] = v;
			for(int j = 1; j*j <= v; j++){
				if(v % j == 0){
					a[block][j]++;
					if(v/j != j)
						a[block][v/j]++;
				}
			}
		}
		else if(op == 1){
			int l, r, x;
			cin >> l >> r >> x;
			l--;
			r--;
			int ans = 0;
			for(int i = l; i <= r; i++){
				int block = i/sq;
				if(i % sq == 0 && i + sq <= r){
						ans += a[block][x];
						//cout << i << " += " << a[block][x] << " | " << block << "\n";
						i += sq-1;
				}
				else if(n[i] % x == 0){
					ans++;
					//cout << i << "++ \n";
				}
			}
			cout << ans << '\n';
		}
		else{
			for(int i = 0 ; i < N; i++){
				if(i%sq == 0) cout << "| ";
				cout << n[i] << " ";
			}
			cout <<  '\n';
		}
	}
}