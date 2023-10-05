#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N, D, a[1000005], psa[1000005];
int l, r;
int sum(int la, int ra){
	return psa[ra] - psa[la-1];
}
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N >> D;
	for(int i = 1; i <= N; i++){
		int b;
		cin >> b;
		a[i] = b;
	}
	for(int i = 1; i <= N; i++){
		psa[i] = psa[i-1] + a[i];
	}
	l = 1;
	r = N;
	while(D--){
		int b;
		cin >> b;

		int f, s;
		f = sum(l, b + l - 1);
		s = sum(b + l , r);
		if(f >= s){
			cout << f <<'\n';
			l = l + b;
		}
		else{
			cout << s <<'\n';
			r = l + b - 1;
		}
	}
}