#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

long long N, P, Q;
long long an[20000005], diff[20000005], mod;
int main(){
	mod = 1e9+7;
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> P >> Q;
	for(long long i = 0; i < N; i++){
		long long a;
		cin >> a;
		an[i] = a;
	}
	long long last = 0;
	for(long long i = 0; i < N; i++){
		diff[N- ((N-i)*P)/Q] += an[i] + 2*diff[i] - last;
		diff[N- ((N-i)*P)/Q] %= mod;

		cout << (an[i] + 2*diff[i])%mod << " ";
		last  = (an[i] + 2*diff[i])%mod;

		diff[i]   %= mod;
		diff[i+1] += diff[i];
		diff[i+1] %= mod;
	}
}