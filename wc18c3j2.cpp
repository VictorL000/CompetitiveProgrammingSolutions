#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;
typedef long long ll;

int N, a ,b;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	a = 0;
	b = 0;
	cin >> N;
	while(N--){
		int g;
		cin >> g;
		if(g <= 100){
			if(g > a){
				b = max(b, a);
				a = g;
			}
			else if(g > b){
				a = max(b, a);
				b = g;
			}
		}
	}
	cout << a + b << '\n';
}