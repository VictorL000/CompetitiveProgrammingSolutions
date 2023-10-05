#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;

int N, a[100005], b[100005];
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N-1; i++){
		int _;
		cin >> _;
		b[i] = _;
	}
	for(int i = 0; i < N; i++)a[i] = 1e6+1;
	for(int i = 0; i < N-1; i++){
		a[i] = min(a[i], b[i]);
		a[i+1] = min(a[i+1], b[i]);
	}
	long long ans = 0;;
	for(int i = 0; i < N; i++)ans += a[i];
	cout << ans;
}