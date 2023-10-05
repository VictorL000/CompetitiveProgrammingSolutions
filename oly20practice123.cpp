#include "bits/stdc++.h"
#ifdef DEBUGM
#define _GLIBCXX_DEBUG
#endif
using namespace std;

long long N;
long long ans;
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	string ns;
	cin >> N;
	ns = to_string(N);
	for(int i = 0; i < (int)ns.length()-1; i+=2 ){	
		ans += (long long )9 * (long long )pow(10, i);
//		cout << ans << '\n';
	}
	if((int)ns.length() % 2 == 1){
//		cout <<1+N - (long long) pow(10, (int)ns.length() - 1) << " is added \n"; 
		ans += (1LL+N - (long long) pow(10, (int)ns.length() - 1));
	}
	if(ans < 0) cout << "overflew";
	cout << ans << '\n';
//	cout << pow(10, (int)ns.length() -1 );
}