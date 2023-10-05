#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N;
long long an[500005], inc[500005], dcr[500005], ans;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		int b;
		cin >> b;
		an[i] = b;
	}
	long long lo = an[0];
	for(int i = 1; i < N; i++){
		inc[i] = inc[i-1] + ( max(1LL*0, lo-an[i]) );
		if(an[i] > lo)lo = an[i];
	}
	lo = an[N-1];
	for(int i = N-2; i >= 0; i--){
		dcr[i] = dcr[i+1] + ( max(1LL*0, lo-an[i]) );
		if(an[i] > lo)lo = an[i];
	}
	ans = inc[0] + dcr[0];
	for(int i = 0; i < N; i++){
		ans = min(ans, inc[i] + dcr[i]);
	}
	cout << ans;
}