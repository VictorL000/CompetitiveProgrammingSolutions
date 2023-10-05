#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;

int N, M;
int main(){
	cin >> N >> M;
	int ans = 0;
	while(N--){
		int a, b;
		cin >> a >> b;
		if( a < M && b > ans) ans = b;
	}
	cout << ans;
}