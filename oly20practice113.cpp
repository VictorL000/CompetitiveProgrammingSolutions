#include "bits/stdc++.h"
using namespace std;
string s, t;
long long hsh[1000005], mod, seed;
long long thsh[1000005];
long long pw[1000005];
set<long long> vis;
long long ans;
long long get_hsh(int l, int r){
	if(l == 0)
		return hsh[r];
	return (hsh[r] - ( hsh[l-1] * pw[r-l+1] + 5*mod ) % mod + 5*mod  ) % mod;
}
int main(){
	cin >> s >> t;
	mod = INT_MAX;
	seed =  31;

	int slen = s.length();
	int tlen = t.length();
	hsh[0] = s[0] - 'a' + 1;
	thsh[0] = t[0] - 'a' + 1;
	pw[0] = 1LL*1;
	for(int i = 1 ; i <= tlen; i++){
		pw[i] = (pw[i-1]*seed+5*mod)%mod;
	}
	for(int i = 1; i < tlen; i++){
		thsh[i] = (thsh[i-1] * seed + 5*mod) % mod + (t[i] - 'a' + 1);
		thsh[i] = (thsh[i] + 5*mod)%mod;
	}
	long long match = thsh[tlen-1];
	for(int i = 1; i < slen; i++){
		hsh[i] = (hsh[i-1] * seed + 5*mod) % mod + (s[i] - 'a' + 1);
		hsh[i] = (hsh[i] + 5*mod)%mod;
	}
	for(int i = 0; i < slen-tlen+1; i++){
		int a = get_hsh(i, i+tlen-1) ;
		if( a == match )ans ++;
	}
	cout << ans;
}