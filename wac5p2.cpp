#include <bits/stdc++.h>
using namespace std;
int N, Q, a[200005], amax[200005], amin[200005];
int main(){
	cin >> N >> Q;
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	int mx, mn;
	amax[N-1] = a[N-1];
	amin[N-1] = a[N-1];
	for(int i = N-2; i >= 0; i--){
		amax[i] = max(a[i], amax[i+1]);
		amin[i] = min(a[i], amin[i+1]);
	}
	sort(begin(amax), begin(amax) + N);

	for(int i = 0; i < Q; i++){
		int l, e;
		cin >> l >> e;
		auto up = upper_bound(begin(amax), begin(amax) + N, l+e) - begin(amax);
		auto lo = upper_bound(begin(amin), begin(amin) + N, l-e-1) - begin(amin);
		cout << N-1 - max( N-1-up, lo-1 ) << "\n";
	}
}