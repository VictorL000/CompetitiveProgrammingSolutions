#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
const long long mod = 1e9+7;
long long bpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int T;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> T;
	while(T--){
		long long a, b, c;
		cin >> a >> b >> c;
		long long n;
		cin >> n;
		if(b - a == c - b){
			cout << (a + ((n-1)*(b-a))%mod)%mod << "\n";
		}
		else{
			cout << ((a%mod) * (bpow(b/a, n-1)%mod)) % mod<< "\n";
		}
	}
}