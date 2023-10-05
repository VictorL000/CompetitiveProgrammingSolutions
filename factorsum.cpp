#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;

long long factorsum(long long a){
	long long ans = 1;
	for(long long i = 2; i*i <= a; i++){
		if(a % i == 0){
			ans += i;
			if(a / i != i)ans += a/i;
		}
	}
	return ans;
}
void factorsum(long long a, long long l){
	if( l > 1000 || a > 1e12){
		cout << "INFINITY\n";
		return;
	}
	ll b = a;
	a = factorsum(a);
	if(a == 1){
		cout << b << " " << l << '\n';
		return;
	}
	factorsum(a, l+1);
}
long long N;
int main(){
	cin >> N;
	while(N--){
		long long a;
		cin >> a;
		factorsum(a, 0LL);
	}
}