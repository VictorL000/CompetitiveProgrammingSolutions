#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;

int N, p[200005], mn, mx;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i =0 ; i < N; i++){
		int o;
		cin >> o;
		p[i] = o;
	}
	if(p[0] > 1){
		cout << -1;
		return 0;
	}
	p[0] = 1;
	for(int i = N-2; i>= 0; i--){
		if(p[i] > 0 && p[i+1] > 1 && p[i] != p[i+1] - 1){
			cout << -1;
			return 0;
		}
		if(p[i+1] > 1)
			p[i] = p[i+1]-1;
	}
	for(int i = 1; i < N; i++){
		if(p[i] == 0)mx++;
		if(p[i] == 1)mn++;
	}
	cout << mn << " " <<mn+mx << '\n';
}