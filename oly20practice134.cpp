#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

int N, an[100005], ans;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> N;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		an[i] = a;
	}
	int curans = 1;
	for(int i = 1; i < N; i++){
		if(an[i] <= an[i-1])curans++;
		else curans = 1;
		if(curans > ans)ans = curans;
	}
	cout << ans << '\n';
}