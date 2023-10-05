#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N;
int a[11];
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		int b;
		cin >> b;
		a[i] = b;
	}
	int ans = 100000000;
	for(long long cnt = 0; cnt < (1 << 11); cnt++){
		int sum = 0;
		for(int i = 0; i < 10; i++){
			if(( 1 << i ) & cnt)
				sum += a[i];
			else sum -= a[i];
		}
		ans = min(ans, abs(sum));
	}

	cout << ans <<'\n';
}